#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

// Antonios Mourtzakis 2119074
// Christos Kourkounas 2119227

int main()
{
    char *ip = "127.0.0.1";
    int port = 5566;

    int sock;
    struct sockaddr_in addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("[-]Socket error");
        exit(1);
    }
    printf("[+]TCP server socket created.\n");

    // Configure server address
    memset(&addr, '\0', sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = port;
    addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the server
    connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    printf("Connected to the server.\n");
    printf("---------------------------------\n");

    srand(time(NULL));

    int tickets_number;
    int flight_number[3];
    int answer;

    // Randomly select the number of tickets (1-3)
    tickets_number = 1 + rand() % 3;

    // Randomly select flight numbers
    for (int i = 0; i < tickets_number; i++)
    {
        flight_number[i] = rand() % 10;
    }

    // Send the number of tickets and flight numbers to the server
    write(sock, &tickets_number, sizeof(int));
    write(sock, flight_number, 3 * sizeof(int));

    // Print client's request
    printf("The client wants %d ticket(s).\n\n", tickets_number);
    for (int i = 0; i < tickets_number; i++)
    {
        printf("Requested flight ID: %d\n", flight_number[i]);
    }

    // Receive and process the server's response
    for (int i = 0; i < tickets_number; i++)
    {
        read(sock, &answer, sizeof(int));
        if (answer > 0) // If booking was successful
        {
            printf("Flight ID %d: --SUCCESSFUL--\n", flight_number[i]);
            printf("Price: %d €\n", answer);
        }
        else // If booking was unsuccessful
        {
            printf("Flight ID %d: --UNSUCCESSFUL--\n", flight_number[i]);
        }
    }

    close(sock);
    printf("---------------------------------\n");
    printf("Disconnected from the server.\n");

    return 0;
}