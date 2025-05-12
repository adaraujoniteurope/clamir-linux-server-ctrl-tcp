#ifndef _application_hpp_
#define _application_hpp_

#include <atomic>
#include <cerrno>
#include <chrono>
#include <cstddef>
#include <service.hpp>

#include <dbus-cxx.h>
#include <thread>

#include <iostream>

class application {
public:
  application() { _quit = false; }
  virtual int initialize() {

    dispatcher = DBus::StandaloneDispatcher::create();

    if (dispatcher == nullptr) {
      return -EINVAL;
    }

    connection = dispatcher->create_connection( DBus::BusType::SESSION );

    if (connection == nullptr) {
      return -EINVAL;
    }

    object = connection->create_object_proxy("clamir.ctrl.server", "/org/nit/clamir/ctrl");

    if (object == nullptr) {
      return -EINVAL;
    }

    return 0;
    
  }
  virtual int run() {

    auto command_processor_legacy_proxy = *(object->create_method<int(int)>("clamir.ctrl.server","command_processor_legacy"));

    while (!_quit) {
      int request = 0;
      std::cin >> request;
      int result = command_processor_legacy_proxy(request);
      std::cout << result;
    }

    return 0;
  }

private:
  std::atomic_bool _quit;
  std::shared_ptr<DBus::Dispatcher> dispatcher;
  std::shared_ptr<DBus::Connection> connection;
  std::shared_ptr<DBus::ObjectProxy> object;
};

#endif