#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
#define NUM 10 // Number of flights

// Antonios Mourtzakis 2119074
// Christos Kourkounas 2119227

struct airport
{
    int flight_id;
    char from_city[15];
    char to_city[15];
    int available_seats;
    int price;
};

int main()
{
    // Socket declarations
    char *ip = "127.0.0.1";
    int port = 5566;

    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;

    // Create server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0)
    {
        perror("[-]Socket error");
        exit(1);
    }
    printf("[+]TCP server socket created.\n");

    // Configure server address
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // Bind the socket to the port
    n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (n < 0)
    {
        perror("[-]Bind error");
        exit(1);
    }
    printf("[+]Bind to the port number: %d\n", port);

    // Initialize flights and cities
    srand(time(NULL));
    struct airport arr_flights[NUM];

    int total_profits = 0; // Total profits of the company
    int total_tickets = 0; // Total tickets sold
    int total_request = 0; // Total requests from clients

    printf("-------------------------\n");
    printf("The cities are:\n");
    printf("1) Athens\n");
    printf("2) Thessaloniki\n");
    printf("3) London\n");
    printf("4) Paris\n");
    printf("5) Rome\n");
    printf("6) Geneva\n");
    printf("7) Venezia\n");
    printf("8) Madrid\n");
    printf("9) Berlin\n");
    printf("10) Dublin\n\n");
    printf("==============================\n");
    printf("The available flights are: %d\n", NUM);
    printf("==============================\n");

    // Initialize flights with random data
    int tocity, fromcity;
    for (int i = 0; i < NUM; i++)
    {
        arr_flights[i].flight_id = i;
        do
        {
            tocity = 1 + rand() % 10;
            fromcity = 1 + rand() % 10;

            // Set departure city
            switch (fromcity)
            {
                case 1: strcpy(arr_flights[i].from_city, "Athens"); break;
                case 2: strcpy(arr_flights[i].from_city, "Thessaloniki"); break;
                case 3: strcpy(arr_flights[i].from_city, "London"); break;
                case 4: strcpy(arr_flights[i].from_city, "Paris"); break;
                case 5: strcpy(arr_flights[i].from_city, "Rome"); break;
                case 6: strcpy(arr_flights[i].from_city, "Geneva"); break;
                case 7: strcpy(arr_flights[i].from_city, "Venezia"); break;
                case 8: strcpy(arr_flights[i].from_city, "Madrid"); break;
                case 9: strcpy(arr_flights[i].from_city, "Berlin"); break;
                case 10: strcpy(arr_flights[i].from_city, "Dublin"); break;
            }

            // Set destination city
            switch (tocity)
            {
                case 1: strcpy(arr_flights[i].to_city, "Athens"); break;
                case 2: strcpy(arr_flights[i].to_city, "Thessaloniki"); break;
                case 3: strcpy(arr_flights[i].to_city, "London"); break;
                case 4: strcpy(arr_flights[i].to_city, "Paris"); break;
                case 5: strcpy(arr_flights[i].to_city, "Rome"); break;
                case 6: strcpy(arr_flights[i].to_city, "Geneva"); break;
                case 7: strcpy(arr_flights[i].to_city, "Venezia"); break;
                case 8: strcpy(arr_flights[i].to_city, "Madrid"); break;
                case 9: strcpy(arr_flights[i].to_city, "Berlin"); break;
                case 10: strcpy(arr_flights[i].to_city, "Dublin"); break;
            }

        } while (fromcity == tocity); // Ensure departure and destination are different

        // Print flight details
        printf("Flight ID %d: %s --> %s\n", arr_flights[i].flight_id, arr_flights[i].from_city, arr_flights[i].to_city);
        arr_flights[i].available_seats = 1 + rand() % 5; // Random available seats (1-5)
        printf("Available seats: %d\n", arr_flights[i].available_seats);
        arr_flights[i].price = 100 + rand() % 400; // Random price (100-500 euros)
        printf("Price: %d euro\n", arr_flights[i].price);
        printf("--------------------------------------------------------------------\n");
    }

    printf("\n");

    // Listen for client connections
    listen(server_sock, 5);
    printf("Listening...\n");

    int client = 0;

    while (1) // Each iteration handles one client
    {
        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);

        printf("################################################################\n");
        printf("[+]Client connected.\n");
        printf("-----------------------\n");

        int tickets_number;
        int flight_number[3];

        // Read the number of tickets from the client
        int bytes_read = read(client_sock, &tickets_number, sizeof(int));
        if (bytes_read == 0) // Client disconnected
        {
            printf("[-]Client disconnected unexpectedly.\n");
            close(client_sock);
            continue; // Wait for the next client
        }

        // Read the flight numbers from the client
        bytes_read = read(client_sock, flight_number, 3 * sizeof(int));
        if (bytes_read == 0) // Client disconnected
        {
            printf("[-]Client disconnected unexpectedly.\n");
            close(client_sock);
            continue; // Wait for the next client
        }

        int answer = 0;

        printf("========================================\n");
        printf("For client %d\n", client + 1);
        printf("=================\n");
        printf("Number of tickets: %d\n", tickets_number);
        printf("Requested flights:\n");

        // Count the total number of requests
        total_request += tickets_number;

        // Process each flight request
        for (int i = 0; i < tickets_number; i++)
        {
            printf("-----------------\n");
            printf("Flight ID: %d\n", flight_number[i]);
            printf("%s --> %s\n", arr_flights[flight_number[i]].from_city, arr_flights[flight_number[i]].to_city);

            int flight_index = flight_number[i];

            if (arr_flights[flight_index].available_seats > 0) // If seats are available
            {
                arr_flights[flight_index].available_seats--; // Reduce available seats
                printf("--Ticket Booking SUCCESSFUL--\n");
                printf("--Price: %d euro--\n", arr_flights[flight_index].price);
                printf("(Remaining seats: %d)\n\n", arr_flights[flight_index].available_seats);

                // Update total profits and tickets sold
                total_profits += arr_flights[flight_index].price;
                total_tickets++;

                answer = arr_flights[flight_index].price;
                write(client_sock, &answer, sizeof(int));
            }
            else // No seats available
            {
                printf("--Warning! Flight %d is fully booked--\n", flight_number[i]);
                printf("--Ticket Booking UNSUCCESSFUL--\n\n");

                answer = 0;
                write(client_sock, &answer, sizeof(int));
            }
        }

        client++;

        close(client_sock);

        printf("================================================================\n");
        printf("--> Total profits: %d €\n", total_profits);
        printf("--> Total requests: %d\n", total_request);
        printf("--> Total tickets sold: %d\n", total_tickets);
        printf("--> Total unsuccessful requests: %d\n", total_request - total_tickets);
        printf("-----------------------\n");
        printf("[+]Client disconnected.\n");
        printf("################################################################\n");
    }

    close(server_sock);
    return 0;
}