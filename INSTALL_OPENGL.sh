#!/bin/bash


# Update packages
sudo apt update


# Install first set of OpenGL dependencies
sudo apt install build-essential freeglut3-dev libxmu-dev -y


# Install second set of dependencies
sudo apt-get install cmake libx11-dev xorg-dev libglu1-mesa-dev freeglut3-dev libglew1.5 libglew1.5-dev libglu1-mesa libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-de