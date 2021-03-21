# Charco

---

[English](../README.md) | [Español](README-es.md) | [日本語](README-jp.md)

---

Charco é um codificador de caráteres.

### Exemplos

```
charco ñ
  UTF-8: C3B1
  UTF-16: 00F1
  Unicode: U+00F1
  HTML: &#241;
  CSS: \00F1

charco -f html 愛
  HTML: &#24859;

charco -f utf8 我
  UTF-8: E68891

```
