# Usage

```
$ docker build -t cxxwrap3 .
$ docker run --rm -it -v $PWD:/work -w /work cxxwrap3 bash -c 'bash build.sh && julia --project -e "using Pkg; Pkg.test()"'
```

# Reference

[my gist](https://gist.github.com/terasakisatoshi/b6a7121cd570f6739992345095b07d62)
