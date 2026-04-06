#include <stdio.h>
#include <winsock2.h>
#include <string.h>

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[1024];
    int addrSize = sizeof(clientAddr);

    // 1. Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Winsock initialization failed\n");
        return 1;
    }

    // 2. Create Socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    // 3. Setup Address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // 4. Bind
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    // 5. Listen
    listen(serverSocket, 5);

    // Console messages in English
    printf("Server started: http://localhost:8080\n");
    printf("Open link in browser and click the button!\n\n");

    // 6. Infinite Loop
    while (1) {
        // Wait for connection
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrSize);

        // Get request from browser
        recv(clientSocket, buffer, sizeof(buffer), 0);

        // === HOMEWORK LOGIC ===
        // Check if the request contains "/button"
        if (strstr(buffer, "GET /button") != NULL) {
            printf(">>> BUTTON PRESSED! Data sent to console.\n");
        }

        // HTML Response (English text)
        const char* html = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "\r\n"
            "<html><body style='font-family: sans-serif; text-align: center; margin-top: 50px;'>"
            "<h1>Homework: The Button</h1>"
            "<a href='/button'><button style='padding: 20px; font-size: 20px; cursor: pointer;'>CLICK ME</button></a>"
            "</body></html>";

        // Send response
        send(clientSocket, html, strlen(html), 0);

        // Close connection
        closesocket(clientSocket);
    }

    // Cleanup
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
