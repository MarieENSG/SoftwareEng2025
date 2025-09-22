# Parent image from debian distribution
FROM debian:stable-slim

# Upgrade system and package manager
RUN apt-get update && apt-get upgrade

# Install tools for C++
RUN apt-get install -y cmake ninja-build build-essential