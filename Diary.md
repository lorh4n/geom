## 📅 25 de Fevereiro de 2026

Hoje retomei o desenvolvimento do projeto `geom` focado em algoritmos geométricos robustos.

### 🚀 Novidades e Integração

- **Estrutura Inicial:** Configurei o projeto com CMake e suporte a C++20.
- **MathVier como Submódulo:** Adicionei a `MathVier` como dependência para lidar com a álgebra linear básica (vetores e matrizes).
- **Primitivas 2D:** Implementei a função `closestPointOnSegment` em `primitives2d.cpp` utilizando os vetores da `MathVier`.
- **Mudança de Testes:** Decidi abandonar o Google Test (GTest) e migrar para o **Catch2**, seguindo o padrão que já utilizo no `MathVier`. Isso vai facilitar a consistência entre os projetos.

### 🛠️ O que foi feito hoje:
- [x] Setup inicial do projeto `geom`.
- [x] Integração da `MathVier` como submódulo Git.
- [x] Implementação de `closestPointOnSegment`.
- [x] Criação deste Diário para acompanhar o progresso.
- [x] Migração do GTest para Catch2.
- [x] Ajustar `tests/test_closest_point.cpp` para Catch2.

---

## ✅ Tarefas Pendentes

- [x] Finalizar a configuração do Catch2 no `CMakeLists.txt`.
- [ ] Implementar Predicados Geométricos Robustos (Orient2D, InCircle).
- [ ] Começar a implementação de Convex Hull (GIFT Wrapping ou Graham Scan).
- [ ] Visualização em Python para os algoritmos de Hull.
