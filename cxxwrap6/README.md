# Usage

```sh
$ docker build -t cxxwrap4 .
$ docker run --rm -it -v $PWD:/work -w /work cxxwrap4 bash -c 'julia --project -e "using Pkg; Pkg.build(); Pkg.test()"'
```

# Reference

[my gist](https://gist.github.com/terasakisatoshi/b6a7121cd570f6739992345095b07d62)
