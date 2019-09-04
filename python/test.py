# Calcular colisões
for x in range(chapa.n):
  for y in range(chapa.n):
    colisoes = []
    corPrimeiraColisao = (255, 255, 255)
    menor = 0

    # Calculando o novo d para o ponto da chapa
    raio.d = Point.usingTwoPoints(p0, chapa.point(x, y))
    
    colisoes += cilindro.verifyColision(raio)
    colisoes += cone.verifyColision(raio)
    colisoes += cubo1.verifyColision(raio) 
    colisoes += cubo2.verifyColision(raio) 
    colisoes += cubo3.verifyColision(raio) 

    # Verificar qual é a primeira colisão
    if len(colisoes) > 0: 
      corPrimeiraColisao = colisoes[0]["color"]
      menor = colisoes[0]["t"]

    for colisao in colisoes:
      if(colisao["t"] < menor):
        menor = colisao["t"]
        corPrimeiraColisao = colisao["color"]

    chapa.matrix[x][y] = corPrimeiraColisao

# Pintar imagem
imagem = Image.new('RGB', (numeroDeFuros, numeroDeFuros))

for x in range(chapa.n):
  for y in range(chapa.n):
    imagem.putpixel( (y,x), chapa.matrix[x][y] )

imagem.save('saida.png')
