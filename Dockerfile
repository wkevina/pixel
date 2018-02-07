FROM ubuntu:17.10

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y libgl1-mesa-dev mesa-common-dev pkg-config

COPY cmake.init CMakeLists.txt
COPY cmake cmake
COPY init ./

RUN ./init

COPY pixel pixel/

RUN ./init
