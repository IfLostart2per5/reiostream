#include <iostream>
#include <string>
#include <vector>

//namespace restd, renovação do std::<comando>
namespace restd {
			//função de print, como uma função, e nao como o std::cout, apesar de usar ele por tras dos panos
			template <typename T>
			int print(T value, std::string end) {
				std::cout << value << end;
				return 0;
			};
			
			//sobrecarga pra caso utilizar-se apenas do valor
			template <typename T>
			int print(T value) {
				std::cout << value << std::endl;
				return 0;
			}
			
		
			//substituto do std::cin, pode receber um prompt e recebe a referencia da variavel
			template <typename T>
			void input(std::string prompt, T& value) {
				std::cout << prompt;
				std::cin >> value;
			};
			
			
		/*
		representação legivel de um dicionario.
		Obs:sei mt bem q poderias usar o std::map, mas isso foi pra aprendizado ;)
		*/	
		template <typename type>
		class dictionary {
			private:
			//chaves e valores
				std::vector<std::string> keys;
				std::vector<type> values;
				
			public:
				//sobeecarregando o operador de indice
				//recebe o tipo do template la em cima
				type operator[](std::string key) {
					type v;
					//um for simples
					for (int i = 0; i < values.size(); i++) {
						if (keys.at(i) == key) {
							v = values[i];
							break;
						}
					}

					return v;
				};
				
			//metodo pra imprimir em string :D	
				std::string toString() {
					//a variavel de representação
					std::string repr;
					
					/*verificando e moldando a representação.
					
					Nao vou documentar mt ate pq pode bagunçar rs*/
					
					//verifica se o dicionario esta vazio
					if (keys.size() == 0) {
						repr = "[ ]";
						
						//mais pra baixo, verifica se ele so tem um elemento
						} else if (keys.size() == 1) {
						repr = "[ " + keys[0] + ": " + std::to_string(values[0]) + " ]";
					} else {
						
						//aq serve pra qnd tem mais de 1 elemento
					repr = "[ ";
					for (int i = 0; i < keys.size(); i++) {
						if (i == keys.size() - 1) {
							repr += keys[i] + ": " + std::to_string(values[i]);
							break;
						} else {
							repr += keys[i] + ": " + std::to_string(values[i]) + ", ";
						};
					}
					repr += " ]";
					};
					
					return repr;
				};
				
				//adiciona um valor ao dicionario
				void add(std::string key, type value) {
					keys.push_back(key);
					values.push_back(value);
				};
				
				//remove um valor
				void remove(std::string key) {
					for(int i = 0; i < keys.size(); i++) {
						if (keys.at(i) == key) {
							keys.erase(keys.begin() + i);
							values.erase(values.begin() + i);
						}
						}
					};
					
					
				//mudas um elemento
				void change(std::string key, type newValue) {
					for (int i = 0; i < this->keys.size(); i++) {
						if (keys.at(i) == key) {
							values[i] = newValue;
							break;
						}
					}
				}
			};

				
			
			
}