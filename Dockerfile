# Stage 1: Builder
# Use an official GCC image as the base for building
FROM gcc:15.2.0 as builder
RUN apt-get update --yes && apt-get install --yes cmake

# Set working directory and copy source code
WORKDIR /app
COPY . /app

# Configure and build using CMake
RUN cmake .
RUN make

# Stage 2: Final
# TODO: Use a minimal base image (e.g., Alpine or a smaller GCC runtime image) for the final runtime environment
FROM gcc:15.2.0 as runtime

WORKDIR /app

# Copy the built executable from the builder stage
COPY --from=builder /app/run_euler /app/run_euler

# Set the entry point command to run the executable
CMD ["./run_euler"]