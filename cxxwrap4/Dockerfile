FROM julia:1.10.4

RUN apt-get update && apt-get install -y --no-install-recommends build-essential cmake \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

RUN julia -e 'using Pkg; Pkg.add("CxxWrap"); Pkg.precompile()'
