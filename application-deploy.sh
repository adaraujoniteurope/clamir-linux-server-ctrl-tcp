#!/bin/bash -e

echo "Copying clamir-linux-server-ctrl-tcp"
ssh -t root@$1 'mkdir -p /usr/local/bin'
scp build-target/clamir-linux-server-ctrl-tcp root@$1:/usr/local/bin