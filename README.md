# Simple Console Timer

A lightweight command-line countdown timer written in C. Perfect for time management, Pomodoro technique, or any task that needs a simple timer.

## Features

- ⏱️ Countdown timer displayed in HH:MM:SS format
- 🔔 Audio beep notification when timer completes (3 beeps)
- ⚙️ Customizable hours, minutes, and seconds
- 🍅 Defaults to 25 minutes (Pomodoro timer)
- 💻 Cross-platform support (Windows and Linux)
- 🪶 Minimal dependencies - just standard C libraries

## Platform Support

- **Linux**: Uses POSIX sleep() and console beep
- **Windows**: Uses Windows.h Sleep() and Beep() functions

## Compilation

### Linux
```bash
gcc -o timer main.c
```

### Windows
```bash
gcc -o timer.exe main.c
```

## Usage

### Basic Usage

Run with default 25-minute timer (Pomodoro):
```bash
./timer
```

### Custom Time

Set hours, minutes, and/or seconds using command-line options:

```bash
# 1 hour timer
./timer -h 1

# 30 minute timer
./timer -m 30

# 90 second timer
./timer -s 90

# Combined: 1 hour, 30 minutes, and 45 seconds
./timer -h 1 -m 30 -s 45
```

## Command-Line Options

| Option | Description | Example |
|--------|-------------|---------|
| `-h <hours>` | Set hours | `-h 2` |
| `-m <minutes>` | Set minutes | `-m 25` |
| `-s <seconds>` | Set seconds | `-s 30` |

**Note:** All options can be combined in any order.

## Examples

```bash
# Quick 5-minute break
./timer -m 5

# 1-hour deep work session
./timer -h 1

# 20-minute workout
./timer -m 20

# 30-second timer
./timer -s 30

# Custom: 2 hours and 15 minutes
./timer -h 2 -m 15
```

## How It Works

1. The timer counts down in real-time, updating the display every second
2. Time is displayed in the format `HH:MM:SS`
3. When the timer reaches zero, it prints "Timer finished!" 
4. Three audio beeps are played to notify completion

## License

This project is open source and available for anyone to use and modify.
