# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

<a href="https://www.packtpub.com/en-us/product/software-architecture-with-c-9781803243016">
  <img src="pics/book_cover.jpg" height="200px" align="right" alt="book cover"/>
</a>

**Architect high-quality C++ applications using modern features and patterns, with expanded coverage of observability
and cloud-native tooling, plus new content on monadic design techniques for modular C++ development.**

### Key features

- Architect high-performance C++ systems using C++20 and beyond
- Build, test, and secure production-ready systems by applying solid design principles
- Manage, package, and deploy cloud-native applications using CMake, Conan, and CI/CD

### Book description

Designing scalable and maintainable software with C++ requires more than language expertise—it demands architectural thinking
and an ability to deliver systems in dynamic environments. This practical guide equips you with the architectural skills
needed to design and build robust, distributed software systems using modern C++.

Starting with fundamental architectural principles and design philosophies, the book walks readers through practical approaches
to designing and deploying reliable systems. This edition includes significant updates and new content: chapters on observability,
package management, and C++ modules address real-world software challenges. Readers will explore software decomposition strategies,
design and system patterns, fault tolerance, API management, and testability—all applied with C++.

Additionally, the book covers modern CI/CD pipelines, cloud-native design, microservices, and modular development,
helping developers navigate today's fast-evolving software landscape. With updated examples and a renewed emphasis
on maintainable and observable architectures, this edition equips C++ professionals to architect modern, production-grade systems.
By the end of this book, you will be able to design, build, test, and deploy enterprise-grade software solutions using
modern C++ and proven architectural techniques.

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

This book is intended for experienced C++ developers and software engineers aiming to expand their architectural knowledge,
lead software projects, or build scalable systems. It assumes readers are comfortable with modern C++ (C++11 onwards)
and familiar with basic design principles and patterns.

<a href="https://www.packtpub.com/">
  <img src="pics/packt-logo.png" height="50px" alt="https://www.packtpub.com/" border="5" align="right"/>
</a>

### Table of contents

**Part 1: Concepts and Components of Software Architecture**

Chapter 1: [Importance of Software Architecture and Principles of Great Design](Chapter01)

Chapter 2: [Architectural Styles](Chapter02)

Chapter 3: [Functional and Nonfunctional Requirements](Chapter03)

**Part 2: The Design and Development of C++ Software**

Chapter 4: [Architectural and System Design Patterns](Chapter04)

Chapter 5: [Leveraging C++ Language Features](Chapter05)

Chapter 6: [Design Patterns and C++ Idioms](Chapter06)

Chapter 7: [Building and Packaging](Chapter07)

Chapter 8: [Package Management](Chapter08)

Chapter 9: [The Future of C++ Code Reuse: Using Modules](Chapter09)

**Part 3: Developing Quality Software**

Chapter 10: [Writing Testable Code](Chapter10)

Chapter 11: [Continuous Integration and Continuous Deployment](Chapter11)

Chapter 12: [Security in Code and Deployment](Chapter12)

Chapter 13: [Performance](Chapter13)

**Part 4: Cloud Native design and distributed systems**

Chapter 14: [Architecture of Distributed Systems](Chapter14)

Chapter 15: [Interservice communication](Chapter15)

Chapter 16: [Containers](Chapter16)

Chapter 17: [Observability](Chapter17)

Chapter 18: [Cloud Native Design](Chapter18)

### Development environment

Follow these guides to configure the development environment:

- [<img src="pics/os/gnu-linux-svgrepo-com.svg" height="18em;"/> Linux environment](devenv_readme/devenv_linux.md)
- [<img src="pics/os/apple-svgrepo-com.svg" height="18em;"/> macOS environment](devenv_readme/devenv_macos.md)
- [<img src="pics/os/microsoft-svgrepo-com.svg" height="18em;"/> Windows environment](devenv_readme/devenv_windows.md)

### C++ compilers

You need at least one of the following compilers:

| No. | Software required    | OS required                        |
| --- | -------------------- | ---------------------------------- |
| 1   | GCC 15               | Windows, Mac OS X, and Linux (Any) |
| 2   | Clang 20             | Windows, Mac OS X, and Linux (Any) |
| 3   | MSVC 19.50 (VS 2026) | Windows                            |

The examples are compatible with earlier versions of C++ compilers (GCC 14, Clang 19 and MSVC 19.44), but not all of them.

We also provide a [PDF file](https://packt.link/gbp/9781803243016) that has color images of the screenshots/diagrams used in this book.

### Instructions and navigations

All the code is organized into folders. For example, Chapter02.

The code will look like the following:

```
  int count = 0;
  for (std::size_t i = 0; i < len; ++i) {
    if (str[i] == '.') count++;
  }
```

### Get to know the authors

**[Adrian Ostrowski](https://aostrowski.github.io/)** [<img src="pics/linkedin-svgrepo-com.svg" height="14em;"/>](https://www.linkedin.com/in/adr-ostrowski/)
is a modern C++ enthusiast interested in the development of both the C++ language itself and the high-quality code written in it.
A lifelong learner with over a decade of experience in the IT industry and more than 8 years of experience with C++ specifically,
he's always eager to share his knowledge. His past projects range from parallel computing, through fiber networking,
to working on a commodity exchange's trading system. Currently, he's one of the architects of Intel and Habana's integration with machine learning frameworks.
In his spare time, Adrian used to promote music bands together with Piotr and has learned how to fly a glider.
Currently, he likes riding his bicycle, going to music events, and browsing memes.

**[Piotr Gaczkowski](https://doomhammer.info)** [<img src="pics/linkedin-svgrepo-com.svg" height="14em;"/>](https://www.linkedin.com/in/piotrgaczkowski/)
has more than 10 years of experience in programming and practicing DevOps and uses his skills to improve people's lives.
He likes building simple solutions to human problems, organizing cultural events, and teaching fellow professionals.
Piotr is keen on automating boring activities and using his experience to share knowledge by conducting courses and writing articles about personal growth and remote work.
He has worked in the IT industry both in full-time positions and as a freelancer, but his true passion is music.
When not making his skills useful at work, you can find him building communities.

**[Andrey Gavrilin](https://gav2xlin.my.canva.site/)** [<img src="pics/linkedin-svgrepo-com.svg" height="14em;"/>](https://www.linkedin.com/in/gav2xlin/)
is a seasoned software engineer who started his journey into software development many years ago. His career began with an eagerness for computer games,
which led to learning C++, Pascal and the assembly language. He has an MSc degree in engineering (industrial automation) and
has worked in different areas which allowed him to gain comprehension of the importance of quality software architecture.
His interests include system, embedded and game programming, electronics. Being an enthusiast of retro gaming and vintage computing,
he enjoys exploring how historical technologies inform modern system design. These hobbies complement his professional work,
providing creative inspiration and perspective on the IT evolution.

If you feel this book is for you, get your copy today!

ISBN:
[978-1803243016](https://nicebooks.com/us/book/101943009-Software-Architecture-with-C-Designing-robust-C) (Paperback)
[978-1803235059](https://isbnsearch.org/isbn/9781803235059) (eBook)

In book stores:

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Packt Publishing (com)**](https://www.packtpub.com/en-us/product/software-architecture-with-c-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Amazon (com)**](https://www.amazon.com/Software-Architecture-Designing-Architectural-Practices/dp/1803243015/)
  [**(com.au)**](https://www.amazon.com.au/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(com.be)**](https://www.amazon.com.be/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(com.br)**](https://www.amazon.com.br/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(com.mx)**](https://www.amazon.com.mx/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(com.tr)**](https://www.amazon.com.tr/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(co.jp)**](https://www.amazon.co.jp/-/en/Software-Architecture-Designing-Architectural-Practices/dp/1803243015/)
  [**(co.uk)**](https://www.amazon.co.uk/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(co.za)**](https://www.amazon.co.za/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(ae)**](https://www.amazon.ae/Software-Architecture-Designing-Architectural-Practices/dp/1803243015/)
  [**(ca)**](https://www.amazon.ca/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(de)**](https://www.amazon.de/-/en/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(eg)**](https://www.amazon.eg/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(es)**](https://www.amazon.es/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(fr)**](https://www.amazon.fr/-/en/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(ie)**](https://www.amazon.ie/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(in)**](https://www.amazon.in/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(it)**](https://www.amazon.it/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(nl)**](https://www.amazon.nl/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(pl)**](https://www.amazon.pl/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(sa)**](https://www.amazon.sa/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(se)**](https://www.amazon.se/Software-Architecture-Designing-architectural-practices/dp/1803243015/)
  [**(sg)**](https://www.amazon.sg/Software-Architecture-Designing-architectural-practices/dp/1803243015/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Google Books (com)**](https://play.google.com/store/books/details/Andrey_Gavrilin_Software_Architecture_with_C?id=DkihEQAAQBAJ)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Apple Books (com)**](https://books.apple.com/us/book/software-architecture-with-c/id6757083961)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **O'Reilly (com)**](https://www.oreilly.com/library/view/software-architecture-with/9781803243016/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **11Street (co.kr)**](https://www.11st.co.kr/products/pa/8988959005)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Abbey's (com.au)**](https://www.abbeys.com.au/book/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-9781803243016.do)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **AbeBooks (com)**](https://www.abebooks.com/9781803243016/Software-Architecture-Designing-robust-systems-1803243015/plp)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Academicbooks.dk (dk)**](https://www.academicbooks.dk/content/software-architecture-c-1)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Accuris (com)**](https://store.accuristech.com/standards/software-architecture-with-c-second-edition?product_id=3043703)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Adlibris (com)**](https://www.adlibris.com/sv/bok/software-architecture-with-c-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Agapea.com (com)**](https://www.agapea.com/libros/Software-Architecture-with-C-Second-Edition-9781803243016-i.htm)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Akademibokhandeln (se)**](https://www.akademibokhandeln.se/bok/software-architecture-with-c/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Aladin (co.kr)**](https://www.aladin.co.kr/shop/wproduct.aspx?ItemId=382759946)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Alibris (com)**](https://www.alibris.com/Software-Architecture-with-C-Designing-Robust-C-Systems-with-Modern-Architectural-Practices-Andrey-Gavrilin/book/56621941)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Angus & Robertson (com.au)**](https://www.angusrobertson.com.au/books/software-architecture-with-c-andrey-gavrilin-adrian-ostrowski-piotr-gaczkowski/p/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Any New Books (com)**](https://anynewbooks.com/book/?asin=1803243015)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Barnes & Noble (com)**](https://www.barnesandnoble.com/w/software-architecture-with-c-second-edition-andrey-gavrilin/1149012873)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Barrett Bookstore (com)**](https://www.barrettbookstore.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Beam e-Books (de)**](https://www.beam-shop.de/belletristik/fremdsprachige-romane/1194826/software-architecture-with-c)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bestseller.si (si)**](https://www.bestseller.si/knjiga/9781803243016/software-architecture-with-c)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Better World Books (com)**](https://www.betterworldbooks.com/product/detail/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Biblio (com)**](https://www.biblio.com/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bigshopper (nl)**](https://bigshopper.nl/product/software-architecture-with-c-designing-robust-c-systems-modern-architectural-practices-3237840209.htm)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Billiger.de (de)**](https://www.billiger.de/offers/685834978737)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Blackwell's (co.uk)**](https://blackwells.co.uk/bookshop/product/Software-Architecture-With-C-by-Andrey-Gavrilin-Adrian-Ostrowski-Piotr-Gaczkowski/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Boekwinkeltjes (nl)**](https://www.boekwinkeltjes.nl/b/241196946/Software-Architecture-with-C-Second-Edition-Designing-robust-C-systems-with-modern-architectural-practices/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bokkilden (no)**](https://www.bokkilden.no/systemanalyse-og-design/software-architecture-with-c-andrey-gavrilin/produkt.do?produktId=214321826)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bokklubben (no)**](https://www.bokklubben.no/systemanalyse-og-design/software-architecture-with-c-andrey-gavrilin/produkt.do?produktId=214321826)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bokus (com)**](https://www.bokus.com/bok/9781803243016/software-architecture-with-c/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bol (com)**](https://www.bol.com/nl/fr/p/software-architecture-with-c/9300000235129507/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **BookFinder.com (com)**](https://www.bookfinder.com/isbn/9781803243016/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bookhype (com)**](https://bookhype.com/index.php/book/show/9f4f448c-db11-415c-81fc-5a012a2ca38a/software-architecture-with-c)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bookmall (co.za)**](https://www.bookmall.co.za/Software-Architecture-with-C-Designing-robust-C-systems-with-modern-architectural-practices-ap-1803243015.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Books etc. (co.uk)**](https://www.booksetc.co.uk/books/view/-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Books-A-Million (com)**](https://www.booksamillion.com/product/1803243015)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bookscape (com)**](https://bookscape.com/product-details/software-architecture-with-c-second-edition-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **BookScouter (com)**](https://bookscouter.com/book/9781803243016-software-architecture-with-c-designing-robust-c-systems-with)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bookshop.org (org)**](https://bookshop.org/p/books/software-architecture-with-c-second-edition-designing-robust-c-systems-with-modern-architectural-practices-adrian-ostrowski/f044411d2201c8ab)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Booksplease (se)**](https://booksplea.se/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-andrey-gavrilin-9781803243016/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **BooksRun (com)**](https://booksrun.com/9781803243016-software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-2nd-edition)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bookstores.com (com)**](https://www.bookstores.com/books/software-architecture-with-c-andrey-gavrilin/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bookswagon (com)**](https://www.bookswagon.com/book/software-architecture-c-adrian-ostrowski/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Booktopia (com.au)**](https://www.booktopia.com.au/software-architecture-with-c-second-edition-andrey-gavrilin/book/9781803243016.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **BookTrapper (com)**](https://booktrapper.com/books/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Browns Books (co.uk)**](https://www.brownsbfs.co.uk/Product/Gavrilin-Andrey/Software-Architecture-with-C/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bruna (nl)**](https://www.bruna.nl/engelse-boeken/software-architecture-with-c-second-edition-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Buchfreund (de)**](https://www.buchfreund.de/de/d/e/9781803243016/software-architecture-with-c-second-edition)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Buffalo Street Books (com)**](https://buffalostreetbooks.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bücher.de (de)**](https://www.buecher.de/artikel/buch/software-architecture-with-c-second-edition/76242185/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **CampusBooks.com (com)**](https://www.campusbooks.com/search/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Cellar Door Bookstore (com)**](https://cellardoorbookstore.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Ceneo (pl)**](https://www.ceneo.pl/192562627)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Chasse aux Livres (fr)**](https://www.chasse-aux-livres.fr/prix/1803243015/software-architecture-with-c-andrey-gavrilin)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Coupang (com)**](https://www.tw.coupang.com/products/%28%E8%8B%B1%E6%96%87%E5%9C%96%E6%9B%B8%29Software-Architecture-with-C%2B%2B---Second-Edition%3A-Designing-robust-C%2B%2B-systems-wi...-%E5%B9%B3%E8%A3%9D%E7%89%88-21009332503728)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **CyberUni**](https://cyberuni.ir/en/book/book-60505/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **De Slegte**](https://www.deslegte.com/software-architecture-with-c-second-edition-5394382/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Desertcart (ae)**](https://www.desertcart.ae/products/803283355-software-architecture-with-c-designing-robust-c-systems-with-modern?source=search)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Dick Smith (com.au)**](https://www.dicksmith.com.au/da/buy/the-nile-software-architecture-with-c-9781803243016/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Direct Textbook (com)**](https://www.directtextbook.com/isbn/9781803243016-software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Dymocks (com.au)**](https://www.dymocks.com.au/software-architecture-with-c-second-edition-by-andrey-gavrilin-and-adrian-ostrowski-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Easy Learning (in)**](https://easylearningdvds.in/product/software-architecture-principles-and-best-practices-using-c/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **eBay (com)**](https://www.ebay.com/sch/i.html?_nkw=9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **eBook.de (de)**](https://www.ebook.de/de/product/52343878/andrey_gavrilin_adrian_ostrowski_piotr_gaczkowski_software_architecture_with_c_second_edition.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Ebookpoint (pl)**](https://ebookpoint.pl/ksiazki/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-s-andrey-gavrilin-adrian-ostrowski-piotr-gaczkowsk,e_4ikt.htm)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **eBooks.com (com)**](https://www.ebooks.com/book/346725460/software-architecture-with-c/andrey-gavrilin/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **eBooks.de (de)**](https://e-books.ciando.com/ebook/bid-4304687-software-architecture-with-c--designing-robust-c-systems-with-modern-architectural-practices.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Ecompare (co.uk)**](https://www.ecompare.co.uk/p/09781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Eichendorff21 (de)**](https://eichendorff21.de/buch/9781803243016/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Enbook (cz)**](https://www.enbook.cz/cs/kniha/software-architecture-with-c-second-edition_50252706)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Enbook (pl)**](https://www.enbook.pl/pl/ksiazka/software-architecture-with-c-second-edition_50252706)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Eslite (com)**](https://www.eslite.com/product/1001294889062307)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Eurobooks (sk)**](https://www.eurobooks.sk/en/software-architecture-with-c-second-edition)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Ex Libris (ch)**](https://www.exlibris.ch/de/buecher-buch/english-books/andrey-gavrilin/software-architecture-with-c-second-edition/id/9781803243016/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Exclusive Books (co.za)**](https://exclusivebooks.co.za/products/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Expert Training (com)**](https://expertrainingdownload.com/product/software-architecture-principles-and-best-practices-using-c/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Fado 168 (com)**](https://fado168.com/us/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-paperback-kindle-1803243015.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Face In A Book (com)**](https://www.getyourfaceinabook.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **FastBooks.eu (eu)**](https://www.fastbooks.eu/book.php?isbn13=9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Feltrinelli (it)**](https://www.lafeltrinelli.it/software-architecture-with-c-designing-libro-inglese-vari/e/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **FindBook (com.tw)**](https://findbook.com.tw/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Fishpond (com)**](https://www.fishpond.com/Books/Software-Architecture-with-C-Second-Edition-Andrey-Gavrilin-Adrian-Ostrowski/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Fnac (com)**](https://www.fnac.com/livre-numerique/a21817433/Andrey-Gavrilin-Software-Architecture-with-C)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Foyles (co.uk)**](https://www.foyles.co.uk/book/software-architecture-with-c/andrey-gavrilin/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **GetTextbooks.com (com)**](https://www.gettextbooks.com/isbn/9781803243016/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Half Price Books (com)**](https://www.hpb.com/software-architecture-with-c---second-edition-designing-robust-c-systems-with-modern-architectural-practices/P-55295644-NEW.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Harvard Book Store (com)**](https://www.harvard.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Haymon Buchhandlung (at)**](https://haymonbuchhandlung.at/item/78397064)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Helion (pl)**](https://helion.pl/ksiazki/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-s-andrey-gavrilin-adrian-ostrowski-piotr-gaczkowsk,e_4ikt.htm)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Hong Kong Book City (com)**](https://www.hkbookcity.com/showbook2.php?serial_no=31842961)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Hugendubel (de)**](https://www.hugendubel.de/de/taschenbuch/andrey_gavrilin_adrian_ostrowski_piotr_gaczkowski-software_architecture_with_c_second_edition-52343878-produkt-details.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **IberLibro.com (com)**](https://www.iberlibro.com/9781803243016/Software-Architecture-Designing-Robust-Systems-1803243015/plp)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Indigo (ca)**](https://www.indigo.ca/en-ca/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices/4f642cc1-2e6c-3599-a59a-49667b0d7be4.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Kinokuniya (com)**](https://united-states.kinokuniya.com/bw/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Kogan.com (com)**](https://www.kogan.com/au/buy/the-nile-software-architecture-with-c-9781803243016/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Krainaksiazek (pl)**](https://krainaksiazek.pl/Software-Architecture-with-C---Second-Edition-Designing-robust-C-systems-with-modern-architectural-practices,9781803243016.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Krisostomus (ee)**](https://www.kriso.ee/software-architecture-cplusplus-designing-robust-cplusplus-db-9781803243016.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Kyobo Mungo (co.kr)**](https://product.kyobobook.co.kr/detail/S000218930778)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Legimi (de)**](https://www.legimi.de/e-book-software-architecture-with-c-andrey-gavrilin,b5127329.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Lehmanns Media (ch)**](https://www.lehmanns.ch/shop/mathematik-informatik/86437275-9781803235059-software-architecture-with-cplusplus)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Lehmanns Media (de)**](https://www.lehmanns.de/shop/naturwissenschaften/80646854-9781803243016-software-architecture-with-cplusplus)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Libreria IBS (it)**](https://www.ibs.it/software-architecture-with-c-designing-libro-inglese-vari/e/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Librerías Gandhi (com.mx)**](https://www.gandhi.com.mx/software-architecture-with-c-9781803235059/p)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Libristo (pl)**](https://www.libristo.pl/pl/ksiazka/software-architecture-with-c-second-edition_50252706)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Libristo (ro)**](https://www.libristo.ro/ro/carte/software-architecture-with-c-second-edition_50252706)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Logobook (ru)**](https://www.logobook.ru/prod_show.php?object_uid=16677426)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Magazyn (pl)**](https://helion.magazyn.pl/Software-Architecture-with-C-Designing-Robust-C-Systems-with-Modern-Architectura/e_4ikt_ebook/ksiazka.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Manz Webshop (at)**](https://shop.manz.at/shop/products/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **MBA Bookstore (com)**](https://mbabookstore.com/product/software-architecture-with-c-2d-edition-by-andrey-gavrilin/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Medimops (de)**](https://www.medimops.de/andrey-gavrilin-software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-paperback-M01803243015.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Mighty Ape (co.nz)**](https://www.mightyape.co.nz/mn/buy/mighty-ape-books-software-architecture-with-c-9781803243016/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **MIT Press (mit.edu)**](https://mitpressbookstore.mit.edu/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Mofibo (com)**](https://mofibo.com/dk/books/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-13244520)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Momox shop (fr)**](https://www.momox-shop.fr/andrey-gavrilin-software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-paperback-M01803243015.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Morawa.at (at)**](https://www.morawa.at/detail/ISBN-2244088350826/Gavrilin-Andrey/Software-Architecture-with-C)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Morgenweb eBooks (com)**](https://morgenweb.ciando-shop.com/ebook/bid-4304687-software-architecture-with-c--designing-robust-c-systems-with-modern-architectural-practices/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Nantucket Book Partners**](https://nantucketbookpartners.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Nejlevnější knihy (cz)**](https://www.nejlevnejsi-knihy.cz/kniha/software-architecture-with-c-second-edition_50252706.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Nextory (com)**](https://nextory.com/es/book/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-5211839)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Northtown Books (com)**](https://www.northtownbooks.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Oblong Books (com)**](https://oblongbooks.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **OpenTrolley (co.id)**](https://opentrolley.co.id/book/9781803243016/software-architecture-w-c-)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Orell Füssli (ch)**](https://www.orellfuessli.ch/shop/home/artikeldetails/A1077805650)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Osiander (de)**](https://www.osiander.de/shop/home/artikeldetails/A1077805650)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **OverDrive (com)**](https://www.overdrive.com/media/12071203/software-architecture-with-c)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Paradigm (com)**](https://reference-global.com/book/9781803235059)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **PChome Online (com.tw)**](https://24h.pchome.com.tw/books/prod/DJBQ3H-D900JI49W)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Pok'elai (com.tw)**](https://www.books.com.tw/products/F01b601515)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Porrua (mx)**](https://porrua.mx/software-architecture-with-c-9781803235059.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Powell's Books (com)**](https://www.powells.com/book/software-architecture-with-c---second-edition-designing-robust-c-systems-with-modern-architectural-practices-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Prairie Lights (com)**](https://prairielights.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Preigu (de)**](https://preigu.de/buecher/software-architecture-with-c-second-edition/134408277)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Printrado (com)**](https://printrado.com/product/software-architecture-with-c/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Prisjakt (nu)**](https://www.prisjakt.nu/search?query=9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Rakuten (co.jp)**](https://books.rakuten.co.jp/rk/4f642cc12e6c3599a59a49667b0d7be4/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Rakuten Kobo (com)**](https://www.kobo.com/us/en/ebook/software-architecture-with-c-1)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Readings (com.au)**](https://www.readings.com.au/product/9781803243016/software-architecture-with-c--andrey-gavrilin-adrian-ostrowski-piotr-gaczkowski--2025--9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **ReadShop (nl)**](https://www.readshop.nl/engelse-boeken/software-architecture-with-c-second-edition-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Saanjhi.com (com)**](https://www.saanjhi.com/products/p_1803243015)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Sandman Books (com)**](https://sandmanbooks.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Sanmin (com.tw)**](https://www.sanmin.com.tw/product/index/015133563)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Saxo (com)**](https://www.saxo.com/dk/software-architecture-with-c-second-edition_bog_9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Schweitzer Fachinformationen (de)**](https://www.schweitzer-online.de/buch/Gavrilin/Software-Architecture-Cplusplus/9781803243016/A74541283/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Sendle (ru)**](https://sendle.ru/1105-obucheniya-vzroslyh-universiteta/397461094219-software-architecture-with-c-designing-robust-c-systems-with-modern-archite.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Shopozz (ru)**](https://shopozz.ru/items/397461094219-software-architecture-with-c-designing-robust-c-systems-with-modern-archite)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Skybook (ir)**](https://skybooks.ir/products/Software-Architecture-with-Cpp)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Storytel (com)**](https://www.storytel.com/books/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices-13244520)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Sundog Books (com)**](https://sundogbooks.com/book/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Surprise Castle**](https://surprisecastle.com/products/software-architecture-with-c-second-edition-designing-robust-c-systems-with-modern-architectural-practices-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Taniomania (pl)**](https://www.taniomania.pl/p/192562627/software-architecture-with-c-designing-robust-c-systems-with-modern)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Target (com)**](https://www.target.com/p/software-architecture-with-c-second-edition-2nd-edition-by-andrey-gavrilin-adrian-ostrowski-piotr-gaczkowski-paperback/-/A-1009426991)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Tenlong (com.tw)**](https://www.tenlong.com.tw/products/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Tertulia (com)**](https://tertulia.com/book/software-architecture-with-c-----second-edition-designing-robust-c---systems-with-modern-architectural-practices-andrey-gavrilin/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **TextbookRush (com)**](https://www.textbookrush.com/browse/books/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **TextbookX (com)**](https://www.textbookx.com/book/Software-Architecture-with-C/9781803243016/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **The Nile (co.nz)**](https://www.thenile.co.nz/books/andrey-gavrilin/software-architecture-with-c/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Thalia (de)**](https://www.thalia.de/shop/home/artikeldetails/A1077805650)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **ThriftBooks (com)**](https://www.thriftbooks.com/w/software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices_piotr-gaczkowski_adrian-ostrowski/57748300/#edition=74880207&idiq=87713972)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Tiendamia (cr)**](https://www.tiendamia.cr/p/amz/1803243015/software-architecture-with-c-designing-robust-c-systems-with-modern)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Tokopedia (com)**](https://www.tokopedia.com/rejekibookstore-1/software-architecture-with-c-second-edition-1733941915957364183)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Torob (com)**](https://torob.com/p/013fd8e9-4890-4f92-bca4-5acd602238c5/software-architecture-with-c%2B%2B/)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Ubuy (com)**](https://www.global.ubuy.com/product/TAK7GA0FE-software-architecture-with-c-designing-robust-c-systems-with-modern-architectural-practices)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Valore (com)**](https://www.valore.com/products/software-architecture-with-c/9781803235059)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **VitalSource (com)**](https://www.vitalsource.com/en-uk/products/software-architecture-with-c-andrey-gavrilin-v9781803235059)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Walmart (com)**](https://www.walmart.com/ip/Software-Architecture-with-C-Second-Edition-Designing-robust-C-systems-with-modern-architectural-practices-Paperback/19019502370)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Waterstones (com)**](https://www.waterstones.com/book/software-architecture-with-c/andrey-gavrilin/adrian-ostrowski/9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **World of Books (com)**](https://www.worldofbooks.com/en-gb/products/software-architecture-with-c-book-andrey-gavrilin-9781803243016)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Yes24 (com)**](https://www.yes24.com/product/goods/171440922)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Świat Czytników (pl)**](https://ebooki.swiatczytnikow.pl/ebook/9781803235059,andrey-gavrilin--adrian-ostrowski--piotr-gaczkowski--software-architecture-with-.html)

In libraries of engineering schools:

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **IEEE Xplore (org)**](https://ieeexplore.ieee.org/book/11321119)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **BUKU (io)**](https://buku.io/book/261381/software-architecture-with-c-13)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Business-Vox (com)**](https://www.business-vox.com/catalog/book/docid/88977053)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Georgia State University (com)**](https://galileo-gsu.primo.exlibrisgroup.com/discovery/fulldisplay/alma9935099577802952/01GALI_GSU:GSU_V1)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **MPG Books (de)**](https://ebooks.mpdl.mpg.de/ebooks/Record/EB002373639)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Pennsylvania State University (edu)**](https://catalog.k8s.libraries.psu.edu/catalog/50132765)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Princeton (edu)**](https://catalog.princeton.edu/catalog/99131714553706421)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **ScholarVox (com)**](https://scholarvox.library.omneseducation.com/catalog/book/docid/88977053)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Skagit Valley College (com)**](https://sbctc-skagit.primo.exlibrisgroup.com/permalink/01STATEWA_SKAGIT/1k7g980/alma991000858304102822)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Stanford (edu)**](https://searchworks.stanford.edu/view/in00000926586)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **University of Pennsylvania (edu)**](https://find.library.upenn.edu/catalog/9979802561103681?hld_id=53899591220003681)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **WorldCat (org) [Paperback]**](https://search.worldcat.org/search?q=isbn%3A1803243015)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **WorldCat (org) [eBook]**](https://search.worldcat.org/search?q=isbn%3A1803235055)

And in other various resources:

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Bookshare (org)**](https://www.bookshare.org/browse/book/6924480)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **iProgrammer (info)**](https://www.i-programmer.info/book-watch-archive/18609-software-architecture-with-c-2nd-ed-packt.html)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Meeting C++ (com)**](https://meetingcpp.com/mcpp/books/book.php?hash=76eab09472533d610f2bf930716181978d0c761e)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Pueblo City-County Library (com)**](https://catalog.pueblolibrary.org/GroupedWork/8bf5a25a-ea04-7185-095a-a6556fd9ac94-eng)

- [<img src="pics/cardboard-box-svgrepo-com.svg" height="14em;"/> **Surrey Libraries (com)**](https://surrey.bibliocommons.com/v2/record/S71C1110729)
