# Charco

<p align="center">
	<a href="../README.md">English</a> |
	<a href="README-es.md">Español</a> |
	<a href="README-pt.md">Portugês</a>
</p>

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
