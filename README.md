# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Table of contents

Part 1: Concepts and Components of Software Architecture

Chapter 1: [Importance of Software Architecture and Principles of Great Design](Chapter01)

Chapter 2: [Architectural Styles](Chapter02)

Chapter 3: [Functional and Nonfunctional Requirements](Chapter03)

Part 2: The Design and Development of C++ Software

Chapter 4: [Architectural and System Design Patterns](Chapter04)

Chapter 5: [Leveraging C++ Language Features](Chapter05)

Chapter 6: [Design Patterns and C++ Idioms](Chapter06)

Chapter 7: [Building and Packaging](Chapter07)

Chapter 8: [Package Management](Chapter08)

Chapter 9: [The Future of C++ Code Reuse: Using Modules](Chapter09)

Part 3: Developing Quality Software

Chapter 10: [Writing Testable Code](Chapter10)

Chapter 11: [Continuous Integration and Continuous Deployment](Chapter11)

Chapter 12: [Security in Code and Deployment](Chapter12)

Chapter 13: [Performance](Chapter13)

Part 4: Cloud Native design and distributed systems

Chapter 14: [Architecture of Distributed Systems](Chapter14)

Chapter 15: [Interservice communication](Chapter15)

Chapter 16: [Containers](Chapter16)

Chapter 17: [Observability](Chapter17)

Chapter 18: [Cloud Native Design](Chapter18)

<a href="https://www.packtpub.com/en-us/product/software-architecture-with-c-9781803243016">
  <img src="pics/cover_image.jpg" height="200px" align="right"/>
</a>

This is the code repository for [Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition](https://www.packtpub.com/en-us/product/software-architecture-with-c-9781803243016), published by Packt.

**Architect high-quality C++ applications using modern features and patterns, with expanded coverage of observability and cloud-native tooling, plus new content on monadic design techniques for modular C++ development.**

### Key features

- Architect high-performance C++ systems using C++20 and beyond
- Build, test, and secure production-ready systems by applying solid design principles
- Manage, package, and deploy cloud-native applications using CMake, Conan, and CI/CD

### Book description

Designing scalable and maintainable software with C++ requires more than language expertise—it demands architectural thinking and an ability to deliver systems in dynamic environments. This practical guide equips you with the architectural skills needed to design and build robust, distributed software systems using modern C++.

Starting with fundamental architectural principles and design philosophies, the book walks readers through practical approaches to designing and deploying reliable systems. This edition includes significant updates and new content: chapters on observability, package management, and C++ modules address real-world software challenges. Readers will explore software decomposition strategies, design and system patterns, fault tolerance, API management, and testability—all applied with C++.

Additionally, the book covers modern CI/CD pipelines, cloud-native design, microservices, and modular development, helping developers navigate today's fast-evolving software landscape. With updated examples and a renewed emphasis on maintainable and observable architectures, this edition equips C++ professionals to architect modern, production-grade systems. By the end of this book, you will be able to design, build, test, and deploy enterprise-grade software solutions using modern C++ and proven architectural techniques.

### What you will learn

- Apply architectural fundamentals to design scalable C++ systems
- Use modern C++ features to create maintainable and secure applications
- Implement architectural and system design patterns
- Design testable code and automate quality checks via CI/CD pipelines
- Manage dependencies and build systems using CMake and Conan
- Explore microservices, containers, and cloud-native practices in C++
- Improve observability with logging, tracing, and monitoring tools
- Build secure, fault-tolerant, and high-performance production-grade software

### Who this book is for

This book is intended for experienced C++ developers and software engineers aiming to expand their architectural knowledge, lead software projects, or build scalable systems. It assumes readers are comfortable with modern C++ (C++11 onwards) and familiar with basic design principles and patterns.

<a href="https://www.packtpub.com/">
  <img src="pics/packt-logo.png" height="50px" alt="https://www.packtpub.com/" border="5" align="right"/>
</a>

If you feel this book is for you, get your copy at
[Amazon](https://www.amazon.com/Software-Architecture-Designing-Architectural-Practices-ebook/dp/B0FGPS463L/)
,[Packt](https://www.packtpub.com/en-us/product/software-architecture-with-c-9781803243016) or
[Barnes & Noble](https://www.barnesandnoble.com/w/software-architecture-with-c-andrey-gavrilin/1147771333) today!

## Development environment

Follow these guides to configure the development environment:

- [<img src="pics/linux-svgrepo-com.svg" height="14em;"/> Linux environment](devenv_readme/devenv_linux.md)
- [<img src="pics/apple-svgrepo-com.svg" height="14em;"/> macOS environment](devenv_readme/devenv_macos.md)
- [<img src="pics/microsoft-svgrepo-com.svg" height="12em;"/> Windows environment](devenv_readme/devenv_windows.md)

### C++ compilers

You need at least one of the following compilers:

| No. | Software required          | OS required                        |
| --- | -------------------------- | ---------------------------------- |
| 1   | GCC 14                     | Windows, Mac OS X, and Linux (Any) |
| 2   | Clang 19                   | Windows, Mac OS X, and Linux (Any) |
| 3   | Microsoft Visual C++ 19.40 | Windows                            |

### Instructions and navigations

All the code is organized into folders. For example, Chapter02.

The code will look like the following:

```
  int count = 0;
  for (std::size_t i = 0; i < len; ++i) {
    if (str[i] == '.') count++;
  }
```

**Following is what you need for this book:**

This software architecture C++ programming book is for experienced C++ developers who are looking to become software architects or are interested in developing enterprise-grade applications.

With the following software and hardware list you can run all code files present in the book (Chapter 1-18).

### Get to know the authors

**Adrian Ostrowski**
is a modern C++ enthusiast interested in the development of both the C++ language itself and the high-quality code written in it. A lifelong learner with over a decade of experience in the IT industry and more than 8 years of experience with C++ specifically, he's always eager to share his knowledge. His past projects range from parallel computing, through fiber networking, to working on a commodity exchange's trading system. Currently, he's one of the architects of Intel and Habana's integration with machine learning frameworks.
In his spare time, Adrian used to promote music bands together with Piotr and has learned how to fly a glider. Currently, he likes riding his bicycle, going to music events, and browsing memes.

**Piotr Gaczkowski**
has more than 10 years of experience in programming and practicing DevOps and uses his skills to improve people's lives. He likes building simple solutions to human problems, organizing cultural events, and teaching fellow professionals. Piotr is keen on automating boring activities and using his experience to share knowledge by conducting courses and writing articles about personal growth and remote work.
He has worked in the IT industry both in full-time positions and as a freelancer, but his true passion is music. When not making his skills useful at work, you can find him building communities.

**Andrey Gavrilin**
is a seasoned software engineer who started his journey into software development many years ago. His career began with an eagerness for computer games,
which led to learning C++, Pascal and Assembly languages. He has an MSc degree in engineering (industrial automation) and
has worked in different areas which allowed him to gain comprehension of the importance of quality software architecture.
His interests include system, embedded and game programming, electronics. Being an enthusiast of retro gaming and vintage computing,
he enjoys exploring how historical technologies inform modern system design. These hobbies complement his professional work,
providing creative inspiration and perspective on the IT evolution.

Vectors and icons by <a href="https://www.svgrepo.com" target="_blank">SVG Repo</a>
