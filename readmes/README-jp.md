# Charco

---

[English](../README.md) | [Español](README-es.md) | [Português](README-pt.md)

---


Charcoは文字エンコーダです。

### 例

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
