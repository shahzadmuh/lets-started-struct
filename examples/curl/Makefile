GCC:=gcc
CFLAG:=-lcurl -ljson-c

all: http_json_curl http_request


http_request:http_get.c

	$(GCC) $(CFLAG) $< -o $@

http_json_curl:json_curl.c
    
	$(GCC) -fsanitize=address $(CFLAG) $< -o $@

clean:
	rm -rf http_request
