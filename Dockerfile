# Dockerfile
# Build Frama-C 22.0 (Titanium) from scratch on Ubuntu 20.04

FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# 1) Install system dependencies
RUN apt-get update && apt-get install -y \
    wget curl opam m4 gcc make git build-essential pkg-config \
    # Optional: some provers or tools
    alt-ergo z3 \
    && rm -rf /var/lib/apt/lists/*

# 2) Initialize OPAM environment
RUN opam init --disable-sandboxing -y

# We switch the shell to bash to run multiple lines of opam commands
SHELL ["/bin/bash", "-c"]

RUN . /root/.opam/opam-init/init.sh && \
    opam switch create 4.08.1_fc22 ocaml-base-compiler.4.08.1 --yes && \
    eval $(opam env) && \
    opam update --yes && \
    opam install depext --yes && \
    opam depext frama-c.22.0 --yes && \
    opam install alt-ergo.2.3.0 why3.1.3.3 frama-c.22.0 frama-c-metacsl.0.1 --yes && \
    why3 config --detect

# 6) Copy your local files into /home/frama/project inside the image
WORKDIR /home/frama/project
COPY . /home/frama/project

# 7) Default command: just drop to a bash shell
CMD ["/bin/bash"]
