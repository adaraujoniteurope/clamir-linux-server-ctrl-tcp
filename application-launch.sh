#!/usr/bin/bash -e

./application-build.sh
./application-deploy.sh $1
./application-debug.sh $1
