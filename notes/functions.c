// TODO: break down that main file into more than just that 
// and start including from src
// do this thing first, think about it first tho
//
// make these functions 
//
// travel through nodes!
// check pipes syntax 
// check redirection syntax 
// check append syntax 
// check heredoc sysntax 
//
//
// NOTE: it's okey to make every function really small,
// becauses that keeps it's objective very clear!
// 
// NOTE: even tho those function are small now! you can always add stuff to them later!
//
//
// TODO: make a struct that has 3 fags 
// error syntax found = 0 (not neccessary if index is used)
// heredoc found = 0 (not neccessary if index is used)
// syntax error before heredoc = 0 (not neccessary if index is used)
// (not neccessary if index is used)
// if heredoc == 1 && syntax error == 0
// 	syntax_error_before_heredoc is set to 1
// have a heredoc index vs syntax error index 
// start looking for the heredoc last
// after checking all the syntax errors! 
// so when you find the heredoc you check if it's index is less
// than the syntax error, and if so, the hredoc should work gets activated
// 
// NOTE: those struct values will be updated inside the functions above
// if syntax error! 
// as for the heredoc thing, that will be a seperate function that travels 
// throught the linked list and prints whether heredoc is found
//
//
// TODO: checks in order
// 1, check syntax first
// 		save the position of it if found
// 2, check grammar/position second
// 		save the position of it if found
// 3, check for heredoc
// 		save the position of it if found
//
// TODO: think about a way to use all this data to build the command
// and also tell to inform the executioner to execute the heredoc only 
// if syntax error was found!
//
// NOTE: so his process will be like this,
// if he finds a syntax error activated and i didn't kill the whole thing
// in case the heredoc came first
// then he executes only that heredoc!
// other than that it's all good
