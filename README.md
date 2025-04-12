# Clock

A simple command-line clock displayer inspired from [tty-clock](https://github.com/xorg62/tty-clock)

## Installation (Debian/Ubuntu and their derivatives only)

```console
cd clock; \
sudo apt install libncurses5-dev; \
make
```

## Usage

```console
./clock [Optional color code]
```
List of color codes:
```
1: Red
2: Green
3: Yellow
4: Blue
5: Purple (Looks pink in some terminals)
6: Cyan
7: White (Default if no color code provided)
```
