# SFML 2.5 in Qt 5 Window

The main part consists of an interface: `ISfQt_canvas`, and a concrete class,
`SfQt_canvas`.
The later uses function objects as its `on_init` and `on_update` functions,
so the entire behavior is set-up by client code.

An alternative would be to derive from `ISfQt_canvas` interface, overriding
the virtual methods directly.

The interface code is heavily inspired by this article:
<http://becomingindiedev.blogspot.com/2013/10/qt-5-and-sfml-20-integration.html>.

If you know a better, cleaner, simpler or more idiomatic way to mix SFML and Qt,
please let me know.
