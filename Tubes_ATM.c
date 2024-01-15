#include <stdio.h>
#include <stdlib.h>


//PIN diset ke konstanta supaya menghindari perubahan value/nilai dari variabel
const int PIN = 9999;
int saldo = 5000000; //set saldo awal rekening

/*procedure cekSaldo () */
/*{Proses : Mencetak jumlah saldo saat ini ke layar}*/
/*{I.S    : - }*/
/*{F.S    : - }*/
void cekSaldo(){
    printf("Saldo anda  sekarang adalah sebesar Rp. %d\n", saldo);
}

/*procedure tarikTunai () */
/*{Proses : Melakukan pengurangan jumlah saldo jika memenuhi syarat (input < saldo-5.0000) }*/
/*{I.S    : saldo tetap }*/
/*{F.S    : Jika tarik tunai kurang dari sama dengan jumlah saldo saat ini dikurang 50000 maka saldo berkurang
            Jika tarik tunai lebih dari jumlah saldo saat ini dikurang 50000 maka saldo tidak berkurang}*/
void tarikTunai(){
    int input;
    printf("Nominal tarik tunai : ");
    scanf("%d", &input);

    if(input <= saldo-50000){
        printf("Saldo ditarik sebesar : Rp. %d\n", input);
        saldo -=input;
        printf("Sisa saldo : %d\n", saldo);
    }else{
        printf("Maaf saldo anda tidak mencukupi\n");
    }
}

/*procedure setorTunai () */
/*{Proses : Menerima input dan melakukan penambahan jumlah saldo}*/
/*{I.S    : - }*/
/*{F.S    : Saldo bertambah }*/
void setortunai(){
    int input;
    printf("Nominal setor tunai : ");
    scanf("%d", &input);
    saldo += input;
    printf("Saldo anda  sekarang adalah sebesar Rp. %d\n", saldo);
}

/*function keluar () */
/*{Mengembalikan nilai 0, selesai melakukan transaksi}*/
int keluar(){
    printf("Terima kasih telah menggunakan mesin ATM Bank Sodikun\n");
    return 0;
}

/*procedure transaksi_lagi (output : check, output : try) */
/*{Proses : Melakukan proses transaksi kembali}*/
/*{I.S    : - }*/
/*{F.S    : - }*/
void transaksi_lagi(int *check, int *try){
    printf("Ingin melakukan transaksi lagi [Y|N] ? ");
    char temp, pilihan;
    scanf("%c%c", &temp, &pilihan); 
    //input user sebelumnya membawa lf(line feed)
    //yang akan ditampung ke variabel temp supaya tidak masuk ke variabel pilihan

    if(pilihan == 'Y'){
        *check = 1;
        *try = 0;
    }else if(pilihan == 'N'){
        printf("Terima kasih telah menggunakan mesin ATM Bank Sodikun\n");
        *check = 0;
    }
}

int main(){
    int try = 0;
    int N, choice;
    int found = 1;
    int count = 1;
    
    while(try<3 && found){
        printf("Masukkan PIN : ");
        scanf("%d", &N);
        if(N == PIN){
            if(count){
                printf("\n"
                        "          Selamat Datang\n" 
                        "      MESIN ATM BANK SODIKUN\n" 
                        "===================================\n");
            }
            printf("<1> Cek Saldo\n"
                    "<2> Tarik Tunai\n"
                    "<3> Setor Tunai\n"
                    "<4> Keluar\n");

            printf("Masukkan pilihan : ");
            scanf("%d", &choice);
            count = 0;
            switch (choice){
                case 1 :
                    cekSaldo();
                    transaksi_lagi(&found, &try);
                    break;
                case 2 :
                    tarikTunai();
                    transaksi_lagi(&found, &try);
                    break;
                case 3 :
                    setortunai();
                    transaksi_lagi(&found, &try);
                    break;
                case 4 :
                    return keluar();
                default:
                    printf("Pilihan anda tidak valid. Pilihan valid adalah [1|2|3|4].\n"
                            "Silahkan coba lagi\n");
                    break;
            }

        }else{
            printf("PIN salah. Silahkan coba lagi\n");
            try++;
        }

        if(try == 3) printf("ATM di blokir, silahkan hubungi Bank Sodikun");
    }
    
    return 0;
}