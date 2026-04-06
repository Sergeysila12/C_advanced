


#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>


#define PORT 8080

// HTML страница с кнопкой
const char* html_page = 
    "<!DOCTYPE html>"
    "<html>"
    "<head><title>Button Test</title></head>"
    "<body>"
    "<h1>Press the button</h1>"
    "<a href='/button'><button>CLICK ME</button></a>"
    "</body>"
    "</html>";

// Обработка запроса кнопки
void handle_button_request(SOCKET clientSocket) {
    printf("\n=== BUTTON PRESSED ===\n");
    printf("Time: Button clicked!\n");
    printf("IP connection active\n");
    printf("=====================\n\n");
}

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[4096];
    int addrSize = sizeof(clientAddr);
    
    // Инициализация Winsock
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    
    // Создание сокета
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Настройка адреса сервера
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    
    // Привязка и прослушивание
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);
    
    printf("HTTP Server started on port %d\n", PORT);
    printf("Open http://localhost:%d in browser\n\n", PORT);
    
    while(1) {
        // Принятие подключения клиента
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrSize);
        
        // Получение HTTP запроса
        recv(clientSocket, buffer, sizeof(buffer), 0);
        
        // Проверка запроса
        if(strstr(buffer, "GET /button") != NULL) {
            // Запрос кнопки - выводим в консоль
            handle_button_request(clientSocket);
            
            // Отправляем ответ
            const char* response = 
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: 100\r\n"
                "\r\n"
                "<html><body><h1>Button Pressed!</h1>"
                "<a href='/'>Go back</a></body></html>";
            send(clientSocket, response, strlen(response), 0);
            
        } else if(strstr(buffer, "GET /") != NULL) {
            // Главная страница
            char response[4096];
            sprintf(response,
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: %zu\r\n"
                "\r\n"
                "%s", strlen(html_page), html_page);
            send(clientSocket, response, strlen(response), 0);
        }
        
        closesocket(clientSocket);
    }
    
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
