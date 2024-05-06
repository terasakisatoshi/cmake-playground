# Usage

```
$ docker build -t cxxwrap1 .
$ docker run --rm -it -v $PWD:/work -w /work cxxwrap1 bash -c 'bash build.sh && julia callcxx.jl'
```

# Reference

[my gist](https://gist.github.com/terasakisatoshi/b6a7121cd570f6739992345095b07d62)
