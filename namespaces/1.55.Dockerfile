FROM gcc:6
RUN apt-get update && \
    apt-get install -y libboost-program-options-dev cmake
