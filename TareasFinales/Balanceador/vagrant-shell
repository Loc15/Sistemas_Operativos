#!/usr/bin/env bash
apt-get update
apt-get install -y haproxy
sudo cp -f /tmp/haproxy /etc/default/
sudo mv /etc/haproxy/haproxy.cfg{,.original}
sudo cp -f /tmp/haproxy.cfg /etc/haproxy/
sudo service haproxy start

