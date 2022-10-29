#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    openlog("assignment2", LOG_PID, LOG_USER);
    if (argc != 3) {
        syslog(LOG_USER | LOG_ERR, "Invalid number of arguments");
        return 1;
    }
    char* filename = argv[1];
    char* str = argv[2];
    int fd = open(filename, O_WRONLY | O_CREAT, S_IRWXU);
    if (fd == -1) {
        syslog(LOG_USER | LOG_ERR, "Error opening %s", filename);
        return 1;
    }
    syslog(LOG_USER | LOG_DEBUG, "Writing %s to %s", str, filename);
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}
