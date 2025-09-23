# Parent image from debian distribution
FROM debian:stable-slim

# Upgrade system and package manager
RUN apt-get update && apt-get upgrade -y

# Install tools for C++
RUN apt-get install -y cmake ninja-build build-essential

# Copy source code
COPY . MyProject

# create build directory
RUN mkdir MyProject/build

# configure and build
RUN cd MyProject/build && cmake -G "Ninja" ..&& ninja && ninja install

# clean
RUN rm -rf MyProject && apt-get purge -y cmake ninja-build

CMD HelloWorld