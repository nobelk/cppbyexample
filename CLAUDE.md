# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C++20 learning project based on examples from https://www.cbyexample.com. The repository contains code snippets demonstrating various C++20 features and patterns.

## Build System

The project uses Make with Clang as the compiler.

### Common Commands

```bash
# Build the executable
make

# Build and run
make run

# Clean build artifacts (removes build/ and bin/ directories)
make clean

# Rebuild from scratch
make rebuild
```

### Build Configuration

- **Compiler**: clang++
- **Standard**: C++20 (`-std=c++2a`)
- **Flags**: `-Wall -Wextra -pedantic`
- **Output**: `bin/cppbyexample`

## Architecture

This is a single-file educational project. All code examples are contained in `main.cpp`, which demonstrates various C++20 language features including:

- Type inference with `auto`
- STL containers (`std::array`, `std::string`)
- Functions (pass-by-value and pass-by-pointer)
- Control flow (loops, conditionals)
- Storage duration specifiers (static, register, extern, _Thread_local)

The Makefile compiles `main.cpp` directly into the executable without intermediate object files.
