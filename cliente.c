#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 12345 /*arbitrário, mas cliente e servidor devem combinar*/
#define BUF_SIZE 4096     /*tamanho do bloco de transferencia*/

int main(int argc,char**argv){

	int c, s, bytes;
	char buf[BUF_SIZE];		/*buffer para arquivo de entrada*/
	structhostent*h;		/*informações sobre servidor*/
	struct sockaddr_in channel	/*mantem endereço IP*/

if(argc!=3) fatal("Usage:cliente server-name file-name");
h=gethostbyname(argv[1		/*pesquisa endereço IP do host*/
if(!h) fatal("gethostbyname failed");

s=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
IF (s<0)fatal("socket");
memset(&channel,0,sizeof(channel));

channel.sin_family=AF_INET;
memcpy(&channel.sh_addr.s_addr,h->h_addr,h_length);
channel.sh_port=htons(SERVER_PORT);

c=connect(s,(struct sockaddr *)&channel,sizeof(channel));
if(c<0)fatal("connect failed");

/*conexão agora esgtabelecida. envia nome do arquivo conbyte 0 no final.*/
write(s,argv[2],strlen(argv[2])+1);

/* captura o arquivo e o escreve na saida padrão.*/
while(1){
	bytes=read(s, buf, BUF_SIZE);	/*lê do soquete*/
	if(bytes<=0 )exit(0);		/*verifica final de arquivo*/
	write(1, buf, bytes);		/*escreve na saida padrão*/
}

}

fatal(char*string);
exit(1);
}





