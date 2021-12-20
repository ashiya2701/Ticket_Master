# Ticket_Master
A System like TicketMaster (or BookMyShow) using OOPs in C++
Ticket Master:
Classes Made: 
Movie
Halls
Cinema
Cities

Class Movie: It has title, genre, language and release date as properties
Parameters in Constructor is made to assign the properties.

Class Halls: Capacity, An object of Class Movie, Vector os int for seats, 
 No. of seats = Capacity,
method set_hall is used to initially set all the seats as zero
method book_seat is used to book a particular seat if available
 Methods for booking seats, Showing all the seats where 0 means available and 1 means booked, provides customers with a way to distinguish between booked and available seats and ensures that no seat is booked twice 
also if all seats are booked it shows that the hall is completely occupied.


Class Cinema: It has a name, vector of Halls as properties
Function of Showing Movie titles in Halls are made - show_halls

Class Cities: City name and a Vector of Cinema are properties
-show_cinema : shows the cinemas in the city: their name
-show_titles: shows movie names in the city and the cinema in which they are
-search_titles: for searching any movie and shows details of the movie found in the city (serach by titles)
-serach_genre: searches movies by genre
-serch_lang: searches movies by language


