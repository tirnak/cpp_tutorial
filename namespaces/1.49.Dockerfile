FROM gcc:4.8
RUN apt-get update && \
    apt-get install -y libboost-program-options-dev cmake
