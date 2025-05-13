#!/usr/bin/bash -e

ssh -t root@$1 'CONFIGURATION_DIRECTORY=/home/clamir/conf gdbserver 0.0.0.0:2000 /usr/local/bin/clamir-linux-server-ctrl-tcp'
