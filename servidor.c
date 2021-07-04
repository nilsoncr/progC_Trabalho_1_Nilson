#include<sys/types/.h>		/*este é o código do servidor*/
#include<sys/fcntl.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#define SERVER_PORT 12345	/*arbitrário, mas cliente e servidor devem combinar*/

#define BUF_SIZE 4096		/*tamanho do bloco de transferência*/
#define QUEUE_SIZE 10


int main(int argc, char*argv[])
{
	int s, b, l, fd, sa, bytes, on=1;
	char buf[BUF_SIZE];			/*buffer para arquivo de saida*/
	struct sockaddr_in channel;		/*mantém endereço IP*/

/*monta estrutura de endereços para vincular ao soquete*/
memset(&channel,0,sizeof(channel));		/*canal zero*/
channel.sin_family= AF_INET;
channel.sin_addr.s_addr= htonl(INADDR_ANY);
channel.sin_port= htons(SERVER_PORT);

/*abertura passiva, espera a conexão*/
s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);	/*cria soquete*/
if(s<0)fatal("socket failed");
setsockopt(s, SOL_SOCKET,SO_REUSEADDR,(char *)&on,sizeof(on);

b= bind(s, (struct sockaddr *) & channel, sizeof(channel);
if(b<0) fatal("bind failed");

l=l isten(s,QUEUE_SIZE;		/*especifica tamanho da fila*/
if(l<0) fatal("listen failed");

/*o soquete agora está preparado e vinculado. espera conexão e a processa*/
while(1){
	sa=accept(s, 0, 0);		/*bloqueia solicitação de conexão*/
	if(sa<0)fatal("accept failed");
	
	read(sa,buf,BUF_SIZE);		/*lê nome do arquivo do soquete*/

/*captura e retorna o arquivo*/
fd=open(buf,O_RDONLY);			/*abre arquivo para ser enviado de volta*/
if(fd<0)fatal("open failed");

while(1){
	bytes=read(fd,buf,BUF_SIZE);	/*lê o arquivo*/
	if(bytes<=0)break;		/*verifica estado final do arquivo*/
	write(sa,buf,bytes);		/*grava bytes no soquete*/
	}

close(fd);
close(sa);

}

}

  
