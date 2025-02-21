# --------------------------------------------------------------------
# Option A: Use a public image with Frama-C 22.0 + WP already installed
# --------------------------------------------------------------------
FROM sverif/frama-c-titanium-docker:latest

# Copy all local files from "project" into /home/frama/ inside container
COPY . /home/frama/project

# Set the working directory
WORKDIR /home/frama/project

# Optionally run "why3 config --detect"
# RUN why3 config --detect || echo "why3 config detection failed"

CMD ["/bin/bash"]
    