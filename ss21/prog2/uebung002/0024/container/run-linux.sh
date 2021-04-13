#!/bin/bash
#export TZ="Europe/Berlin"
#ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
#apt-get update
#apt-get install -y tzdata
#apt-get upgrade -y
#apt-get install build-essential libglfw3-dev zip -y

cd /container
#make clean
make LINUX
