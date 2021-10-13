# Intent Recognition Program

This is a simple command line intent recognition tool. This also includes a google test suite for unit testing.



# How to execute
- $ git clone https://github.com/binoykv/intentRecognition.git
- $ mkdir build && cd build && cmake ../intentRecognition && make
  > Now the binaries are generated in the **build** directory (which you are already in)
- ./application   --> For running the application
- ./googleTest    --> For running the unit tests and getting the output

## Application sample output
  $./application
  
 '##### This is a command line tool for intent recognition #####
 
 (Enter Close/Exit to stop the program)
 
'> Get Weather

What is the weather like today?

'> Get Weather Berlin

What is the weather like in Berlin today?

'> Get Fact

Tell me an interesting fact.

'> Get Something

Unknown command

'>Close

Program exited!!

> The program can handle different semantic variations for various commands
> As of now the available commands are "Get Weather", "Get Weather  <city<>", "Get Fact"
