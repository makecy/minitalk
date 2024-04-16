# Minitalk

## Overview
This is a simple implementation of the Minitalk project for 42 school. Minitalk is a small data exchange program using UNIX signals. The project involves creating a client and server program where the client sends a string message to the server using only signals. 

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Installation
To use this project, simply clone this repository to your local machine using the following command:


## Usage
Once you have cloned the repository, navigate to the project directory and compile the server(also bonus) and client(also bonus) programs using the provided Makefile:


This will generate two executables named `server` and `client`. You can then run the server and client in separate terminal windows to communicate with each other.

To start the server, run:
./server or ./server_bonus


To start the client, run:
./client `[server_pid]` `[message]` or ./client_bonus [`server_pid]` `[message]`


## Contributing
Contributions to this project are welcome! If you have any ideas for improvements or new features, feel free to open an issue or create a pull request.

## License
This project is licensed under the [MIT License](LICENSE).


