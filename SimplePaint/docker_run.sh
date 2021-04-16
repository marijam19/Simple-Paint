#!/bin/bash

xhost +

sudo docker run --net=host --env="DISPLAY" --volume="$HOME/.Xauthority:/root/.Xauthority:rw" simplepaint:latest
