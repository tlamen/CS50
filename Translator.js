let navbar_1_EN = "Football"
let navbar_1_PT = "Futebol"
let navbar_2_EN = "Music"
let navbar_2_PT = "Música"
let texto_1_EN = "&nbsp;&nbsp;Hello, world! This is my first Webpage created for 2020 CS50's pset8 in the Web track. This simple homepage will show a brief biography about myself and present a few ideas I've been developing with this course's final project in mind.";
let texto_1_PT = "&nbsp;&nbsp;Olá, mundo! Essa é minha primeira página na Web, criada para o pset8 do curso CS50 2020 no curso Web. Essa simples página vai mostrar uma breve biografia sobre mim e apresentar algumas ideias que tenho desenvolvendo com o projeto final do curso em mente.";
let header_1_EN = "Welcome to my webpage!"
let header_1_PT = "Bem-vindo à minha página!"
let texto_2_EN = "&nbsp;&nbsp;Since I was a young kid I had contact with computers, technology and videogames. But it was only at the age of 16 that I grew interested in programing and computer science. I started taking some online courses but with no clear direction on what to learn and how to use my knowledge. I got the oportunity to visit some universities in the United States, and bought a book to learn to code with java. But the lack of time because of school and bad pacing of learning computer science from a book made me give up after some months. Only with the covid-19 crisis and the social distancing I found time to retake my studies about coding, and that's when I found the CS50's introduction to computer science, from the Harvard University. Now at my last year of high school, and universities' approval exams being postponed due to the pandemic crysis, I started learning a lot and having a much brighter perspective of computer science."
let texto_2_PT = "&nbsp;&nbsp;Desde que eu era criança eu tive contato com computadores, tecnologia e videogames. Mas foi apenas com 16 anos que comecei a me interessar em programação e ciências da computação. Eu comecei fazendo alguns cursos online, mas sem nenhuma ideia clara de direção sobre o que aprender ou como usar meu conhecimento. Eu tive a oportunidade de visitar algumas universidades nos Estados Unidos, e comprei um livro para aprender programação em Java. Mas a falta de tempo por causa da escola e o ritmo de aprendizado ruim ao aprender ciências da computação com um livro me fez desistir alguns meses depois. Somente com a crise do covid-19 e o distanciamento social eu encontrei tempo para retomar os estudos sobre programação, e foi quando eu encontrei o curso do CS50 de introdução a ciências da computação, da Universidade de Harvard. Agora no meu último ano do ensino médio e com os vestibulares adiados devido à pandemia, eu comecei a aprender muito e ter uma perspectiva bem mais clara sobre ciências da computação."
let header_2_EN = "About myself:"
let header_2_PT = "Sobre mim:"
let header_3_EN = "So, What's next to me?"
let header_3_PT = "Então, o que farei a seguir?"
let texto_3_EN = "&nbsp;&nbsp;As you can see, it took me a lot of time to really engage in computer science. But what's my next step going to be? Well. I have a few thoughts about how I want to present my final project of this course, so I decided to show them in this page! I present three initial ideas of possible projects I plan to develop. Those projects were all based on three of my greatest passions in life, so if you are interested in learnin a bit more about any of those ideas, and about myself, just click the names in the navbar above. Hope you enjoy it!"
let texto_3_PT = "&nbsp;&nbsp;Como podem ver, demorou muito tempo para eu realmente me comprometer com ciências da computação. Mas qual será meu próximo passo? Bem, eu tenho algumas ideias de como eu quero apresentar meu projeto final desse curso, então decidi que vou mostrá-las nessa página! Eu apresentei três ideias iniciais de possíveis projetos que planejo desenvolver. Todos esses projetos foram baseados em três das minhas paixões na vida, então se tiverem interesse em conhecer um pouco mais sobre essas ideias, e sobre mim mesmo, é só clicar nos nomes na barra de navegação lá em cima. Espero que gostem!"
let header_4_EN = "Thanks:"
let header_4_PT = "Agradecimentos:"
let texto_4_EN = "&nbsp;&nbsp;I'd like to say thank you to everyone who's been helping me in this journey. Thanks to my family, specially my mother, my father, my grandparents and my girlfriend, who've been supporting me taking this course since the beggining. Thanks to my friends from the Imortal Kings server, who are involved in the videogame project, and whose friendship is very meaningful to me. And finnaly, thank you to all my cs50 teachers. This course has been amazingly build and I wanted to take the opportunity of expressing myself in this webpage to thank you all!"
let texto_4_PT = "&nbsp;&nbsp;Eu gostaria de agradecer a todos que me ajudaram nessa jornada até aqui. Obrigado à minha família, especialmente minha mãe, meu pai, meus avós e minha namorada, que me incentivaram a fazer esse curso desde o começo. Obrigado à meus amigos do servidor Imortal Kings, que estão envolvidos no projeto de videogames, e com quem tenho amizades muito significativas para mim. E finalmente, obrigado a todos meus professores do cs50. Esse curso foi muito bem construido e eu quero aproveitar essa oportunidade de me expressar nessa página para agradecer a todos vocês!"

function toPortugueseNavbar()
{
    document.querySelector('#futebol').innerHTML = navbar_1_PT;
    document.querySelector('#musica').innerHTML = navbar_2_PT;
}

function toEnglishNavbar()
{
    document.querySelector('#futebol').innerHTML = navbar_1_EN;
    document.querySelector('#musica').innerHTML = navbar_2_EN;
}

function toEnglishIndex()
{
    toEnglishNavbar();
    document.querySelector('#text1').innerHTML = texto_1_EN;
    document.querySelector('#header1').innerHTML = header_1_EN;
    document.querySelector('#text2').innerHTML = texto_2_EN;
    document.querySelector('#header2').innerHTML = header_2_EN;
    document.querySelector("#image1").src = "media/GraficoEN.png";
    document.querySelector('#header3').innerHTML = header_3_EN;
    document.querySelector('#text3').innerHTML = texto_3_EN;
    document.querySelector('#header4').innerHTML = header_4_EN;
    document.querySelector('#text4').innerHTML = texto_4_EN;
}

function toPortugueseIndex()
{
    toPortugueseNavbar();
    document.querySelector('#text1').innerHTML = texto_1_PT;
    document.querySelector('#header1').innerHTML = header_1_PT;
    document.querySelector('#text2').innerHTML = texto_2_PT;
    document.querySelector('#header2').innerHTML = header_2_PT;
    document.querySelector("#image1").src = "media/GraficoPT.png";
    document.querySelector('#header3').innerHTML = header_3_PT;
    document.querySelector('#text3').innerHTML = texto_3_PT;
    document.querySelector('#header4').innerHTML = header_4_PT;
    document.querySelector('#text4').innerHTML = texto_4_PT;
}

function toEnglishFootball()
{
    toEnglishNavbar();
    document.querySelector('#title').innerHTML = "Football project"
    document.querySelector('#subtitle').innerHTML = "Making football tactics accesible and easier to understand and share"
    document.querySelector('#text1').innerHTML = "&nbsp;&nbsp;Like most brazilians, football (or soccer, as you say in the USA) is one of my greatest passions in life. I've been supporting the brazilian national 'seleção' and my local club EC Bahia since the early days of my childhood. Though it was always a stage of passsion, power and ability, during the recent lockdown I grew interested in a new perspective on football: the technical and tactital analysis."
    document.querySelector('#header').innerHTML = "Making a football tactits web application:"
    document.querySelector('#text2').innerHTML = "&nbsp;&nbsp;My most developed (at least in my mind) idea for a final project is of creating a website where people could edit and share custom football tactics. Anyone could create a system and upload it to a online library, so people could use it to have a better understanding of the game, or apply the tactics with their local teams, in football videogames, or in any other mean they want. Below, there's a (very) basic example that shows some tactic formations:"
}

function toPortugueseFootball()
{
    toPortugueseNavbar();
    document.querySelector('#title').innerHTML = "Projeto de futebol"
    document.querySelector('#subtitle').innerHTML = "Deixando as táticas de futebol mais acessíveis e mais faceis de serem entendidas e compartilhadas"
    document.querySelector('#text1').innerHTML = "&nbsp;&nbsp;Como muitos brasileiros, futebol é uma das grandes paixões da minha vida. Eu tenho torcido para a seleção brasileira e para meu time local, EC Bahia, desde o começo de minha infância. Apesar de ser sempre um ambiente de paixão, poder, garra e habilidade, durante a recente quarentena eu comecei a me interessar em uma perspectiva diferente no futebol: a análise técnica e tática"
    document.querySelector('#header').innerHTML = "Fazendo um aplicativo web de táticas de futebol:"
    document.querySelector('#text2').innerHTML ="&nbsp;&nbsp;Minha ideia mais desenvolvida (pelo menos na minha cabeça) para o projeto final é criar um site onde pessoas poderiam editar e compartilhar táticas customizadas. Qualquer um poeria criar um sistema e fazer upload para uma biblioteca online, onde pessoas poderiam usar para ter um melhor entendimento do jogo, ou aplicar as táticas em seus times locais, ou em videogames de futebol, ou de qualquer outra forma que desejassem. Abaixo, há um exemplo (muito) básico que mostra algumas formações táticas:"
}

function toEnglishMusic()
{
    toEnglishNavbar();
    document.querySelector('#title').innerHTML = "Music project"
    document.querySelector('#subtitle').innerHTML = "What music is, how does it feels, and how it is present in the life of each one of us"
    document.querySelector('#text1').innerHTML = "&nbsp;&nbsp;Music has a huge importance in my life, since its power to make us feel better during hard times, to integrate people together (I'd say it's a bit like the internet itself). Applications like spotify, shazam and iTunes explored this importance of music in our daily lifes and helped bringing music with easiness and security to million of people around the world, demonstrating the power of technology to potencialize music's effects."
    document.querySelector('#header').innerHTML = "So what's my project on music?"
    document.querySelector('#text2').innerHTML = "&nbsp;&nbsp;Well, I think this is my most unclear project idea on what to do. Since music's traditional proposals were already largely explored, I thoght I could come up with something that explores more subjective aspects of music, like the feelings while listening a song we love, how music can help people during therapy and how can music become something so passioate and relevant in our lifes. Maybe I'll develop some kind of social media where people can discuss these topics and share their personal experiences, but again, this is just a bare idea of how I could improve people's life using computer science and integrate it to music."
}

function toPortugueseMusic()
{
    toPortugueseNavbar();
    document.querySelector('#title').innerHTML = "Projeto de música"
    document.querySelector('#subtitle').innerHTML = "O que é a música, como ela é sentida, e como ela está presente na vida de cada um de nós"
    document.querySelector('#text1').innerHTML = "&nbsp;&nbsp;A música tem uma importância imensa na minha vida, desde seu poder de nos fazer sentir melhor em momentos dificeis, até integrar pessoas umas com as outras (eu diria que é parecido com o que a internet faz). Aplicativos como spotify, shazam e iTunes exploraram essa importâmcia da música nas nossa vidas diárias e ajudaram a trazer música com facilidade e segurança para milhões de pessoas ao redor do mundo, demonstrando o poder da tecnologia para potencializar os efeitos da música"
    document.querySelector('#header').innerHTML = 'Então, qual meu projeto sobre música?'
    document.querySelector('#text2').innerHTML = "&nbsp;&nbsp;Bem, eu acho que essa é a ideia de projeto menos clara que tenho no momento. Como as propostas mais tradicionais de música já foram amplamente exploradas, eu pensei que poderia pensar em algo que explorasse aspectos mais subjetivos da música, como o que sentimos enquanto ouvimos uma música que amamos, como música pode ajudar pessoas durante terapias, e como a música se tornou algo tão apaixonante e relevante na vida de todos. Talvez eu desenvolva algum tipo de rede social, onde pessoas possam discutir esses tópicos e compartilhar suas experiências pessoais, mas de novo, isso é só uma ideia simples de como eu poderia melhorar a vida das pessoas usando da computação e integrando-a com a música."
}

function toEnglishVideogames()
{
    toEnglishNavbar();
    document.querySelector('#title').innerHTML = "Videogame project"
    document.querySelector('#subtitle').innerHTML = "The challenges and perspectives of creating a videogame"
    document.querySelector('#text1').innerHTML = "&nbsp;&nbsp;I always loved to play videogames throughout my life. Since early consoles like the playstation 2 in my childhood, to playing online with people from all arround the world with my computer. Games started to become more than a simple way of entertainment, but a form of art, and a mean to connect people: the ones who play it and the ones who develop it."
    document.querySelector('#header1').innerHTML = "So, am I going to create my own videogame?"
    document.querySelector('#text2').innerHTML = "&nbsp;&nbsp;This answer doesn't depend only on me. Playing online games for some years from now, I ended up knowing many cool people, and we ended up creating and administrating a discord server with nearly one hundred members. Recently, we've been growing up together and developed similar interests in engineering, coding and game design, and after some discussion we thought about creating a game together someday. It's still a very superficial idea, I would need to take CS50's games track or take another course on game design, and many of them would need to learn more about programing. But if everyone gets involved in the idea, we might end up developing our own game!"
    document.querySelector('#text3').innerHTML = "&nbsp;&nbsp;Here, to give credit to my friends on the server who were interested in this idea (and also to include another mandatory html tag), I came up with this table describing each one's skills and formation."
    document.querySelector('#th1').innerHTML = "Name"
    document.querySelector('#th2').innerHTML = "Skills and knowledge"
    document.querySelector('#skul').innerHTML = "Experience in pixel art and unity engine game design"
    document.querySelector('#noob').innerHTML = "Experience in roblox game designs and unity engine"
    document.querySelector('#gab').innerHTML = "Started mechanical engineering and experience with programming in C and C++"
    document.querySelector('#igor').innerHTML = "Started electrical engineering and good experience with programming"
    document.querySelector('#luigi').innerHTML = "Learning coding and experience with technical courses"
    document.querySelector('#header2').innerHTML = "First character design by skul_rock:"
}

function toPortugueseVideogames()
{
    toPortugueseNavbar();
    document.querySelector('#title').innerHTML = "Projeto de videogames"
    document.querySelector('#subtitle').innerHTML = "Os desafios e as perspectivas de criar um jogo"
    document.querySelector('#text1').innerHTML = "&nbsp;&nbsp;Eu sempre amei jogar videogames durante minha vida inteira. Desde os primeiros consoles como o playstation 2 na minha infáncia, até jogar online com pessoas de todos os lugares do mundo no meu computador. Jogos começaram a se tornar mais do que uma simples forma de entretenimento, mas também uma forma de arte, e um meio de conectar pessoas: tanto as que jogam o jogo como aqueles que o desenvolvem."
    document.querySelector('#header1').innerHTML = "Então, eu vou criar meu próprio videogame?"
    document.querySelector('#text2').innerHTML = "&nbsp;&nbsp;Essa resposta não depende só de mim. Jogando online há alguns anos, eu acabei conhecendo muitas pessoas legais, e acabamos criando e administrando um servidor no discord que hoje tem quase cem membros. Recentemente, crescendo juntos nós desenvolvemos interesses em comum como engenharia, programação e design de jogos, e depois de algumas discussões nós pensamos em criar um jogo juntos algum dia. Ainda é uma ideia bem superficial, eu precisaria fazer o curso de games do CS50 ou outro curso de game design, e muitos deles iriam ter de aprender mais sobre programação. Mas se todos se envolverem com a ideia, nós podemos acabar desenvolvendo nosso próprio jogo!"
    document.querySelector('#text3').innerHTML = "&nbsp;&nbsp;Aqui, para creditar meus amigos do servidor que se interessaram nessa ideia (e também para incluir mais uma tag html obrigatória), I fiz essa tabela descrevendo as habilidades e a formação de cada um."
    document.querySelector('#th1').innerHTML = "Nome"
    document.querySelector('#th2').innerHTML = "Habilidades e conhecimento"
    document.querySelector('#skul').innerHTML = "Experiência em pixel art e em game design com engine unity"
    document.querySelector('#noob').innerHTML = "Experiência em game design em jogos de roblox e engine unity"
    document.querySelector('#gab').innerHTML = "Cursando engenharia mecânica e experiência com programação em C e C++"
    document.querySelector('#igor').innerHTML = "Cursando engenharia elétrica e boa experiência com programação"
    document.querySelector('#luigi').innerHTML = "Aprendendo programação e experiência em cursos técnicos"
    document.querySelector('#header2').innerHTML = "Primeiro design de personagem por skul_rock:"
}

function t343()
{
    document.querySelector("#image1").src = "media/tactics/343.png"
}

function t352()
{
    document.querySelector("#image1").src = "media/tactics/352.png"
}

function t433()
{
    document.querySelector("#image1").src = "media/tactics/433.png"
}

function t442()
{
    document.querySelector("#image1").src = "media/tactics/442.png"
}

function t451()
{
    document.querySelector("#image1").src = "media/tactics/451.png"
}

function t532()
{
    document.querySelector("#image1").src = "media/tactics/532.png"
}

function tClear()
{
    document.querySelector("#image1").src = "media/tactics/Empty.png"
}
