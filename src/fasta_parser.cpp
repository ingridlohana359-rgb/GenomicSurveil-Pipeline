#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Estrutura simples para armazenar a sequência
struct Sequence {
    string header;
    string data;
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Uso: " << argv[0] << " <arquivo_entrada.fasta> <arquivo_saida.csv>\n";
        return 1;
    }

    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Erro ao abrir os arquivos.\n";
        return 1;
    }

    outfile << "ID_Sequencia,Tamanho,Conteudo_GC_Estimado\n";

    string line, header = "", seq = "";
    while (getline(infile, line)) {
        if (line.empty()) continue;
        if (line[0] == '>') {
            if (!header.empty()) {
                // Processa a sequência anterior
                int size = seq.length();
                int gc_count = 0;
                for(char c : seq) if(c == 'G' || c == 'C' || c == 'g' || c == 'c') gc_count++;
                float gc_per = (size > 0) ? ((float)gc_count / size) * 100 : 0.0;
                
                outfile << header.substr(1) << "," << size << "," << gc_per << "\n";
            }
            header = line;
            seq = "";
        } else {
            seq += line;
        }
    }
    // Última sequência
    if (!header.empty()) {
        int size = seq.length();
        int gc_count = 0;
        for(char c : seq) if(c == 'G' || c == 'C' || c == 'g' || c == 'c') gc_count++;
        float gc_per = (size > 0) ? ((float)gc_count / size) * 100 : 0.0;
        outfile << header.substr(1) << "," << size << "," << gc_per << "\n";
    }

    cout << "[C++] Processamento de sequencias concluido com sucesso!\n";
    return 0;
}
