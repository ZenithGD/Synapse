# Synapse

## What is Synapse?
It is a tiny library for representing neural networks, mainly for learning and playing with them. I hope you can find it useful!

## How can I install the library?

You can directly clone the repository via this command:

```
git clone --recurse-submodules https://github.com/ZenithGD/Synapse.git
```

This loads the source and every required submodule. This library relies on the following libraries, which can be found in the vendor folder:
- [linalg](https://github.com/sgorsten/linalg) for algebraic computation.
- [spdlog](https://github.com/gabime/spdlog) for logging on debug

## What can I do with Synapse?

You can easily define ANNs with the provided API, which is similar to the Keras API in Python, by pushing layers onto an ANN object. 

## What is Synapse going to be?

I'm planning on adding ANN and automatic supervised learning support on the short term, but i'd really like to try extending the API for constructing CNNs, optimization methods for learning, etc... If you have any ideas or you want to contribute to the project, you are welcome to do so!
