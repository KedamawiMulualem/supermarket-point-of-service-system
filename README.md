# supermarket-point-of-service-system
A small market maintains an inventory of  exactly 20 items. You will read these items  from a file. Each item named will have an  associated cost and a character code to  indicate whether or not it is taxable. You will  place your online order. A file will contain  your "printed" receipt with the total amount of  your order.
A small market maintains an inventory of

exactly 20 items. You will read these items

from a file. Each item named will have an

associated cost and a character code to

indicate whether or not it is taxable. You will

place your online order. A file will contain

your "printed" receipt with the total amount of

your order.

Project Specifications

Input for this project has two sources. The

inventory of exactly 20 items (with cost and

tax code for each) is read from an input file.

The user must enter: the names of the input

and output files, and the items to purchase

(by the number code associated with each

item.)

Input file: Minimart.txt

Output also has two sources. The command

line shows the names of the inventory items,

the echo of the chosen item with its price and

"taxable" if appropriate. The amount of the tax

and the total amount due will appear on the

command line screen when the user is

finished. The tax rate is 7% (use .07 in your

code.) The "printed" receipt will be on the

output file. All the non­taxable items should

be listed first followed by the taxable items,

then the total amount of the tax, and last the

total amount due.

Processing Requirements

Create the functions for the following:

1. Read the inventory: Prompt for and

get the input file name, open the file, read the

items from the file, and store them into the

three parallel arrays. The three arrays will be

passed as parameters. (NO GLOBAL

VARIABLES) Assume that the file contains

exactly 20 lines of input and is constructed

correctly. Return 0 to the calling function if

the file opens, ­1 if the file is not found. If the

file is not found,
