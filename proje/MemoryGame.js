var score = 0;
var expectedCard = 1;
var gameStarted = false;

function shuffleAndCoverCards() {
    gameStarted = true;
    //burdan sonra butonlarin durumu baslangica hazir hale geliyor
    document.getElementById("shuffleAndCoverBtn").setAttribute("disabled", true);
    document.getElementById("shuffleAndCoverBtn").style.pointerEvents = "none";
    document.getElementById("shuffleAndCoverBtn").style.opacity = "0.5";
    document.getElementById("restartBtn").removeAttribute("disabled");
    document.getElementById("restartBtn").style.pointerEvents = "auto";
    document.getElementById("restartBtn").style.opacity = "1";
    document.getElementById("restartBtn").style.display = "inline-block";
    

    var container = document.getElementById("cardContainer");

    // Kartları karıştır
    for (var i = container.children.length; i >= 0; i--) {
        container.appendChild(container.children[Math.random() * i | 0]);
    }

    // Kartları 2 saniye sonra kapat
    setTimeout(function () {
        var columns = document.getElementsByClassName("column");
        for (var i = 0; i < columns.length; i++) {
            columns[i].classList.add("covered");
        }
    }, 1500);

    // Skoru sıfırla
    score = 0;
    updateScore();
    expectedCard = 1;

    // Mesajları sıfırla
    resetMessages();
}

function revealCard(element, card) {
    // Kartın üstü siyah ise ve "You lost!" mesajı yoksa
    if (element.classList.contains("covered") && !document.getElementById("message").innerText) {
        // Kartın üzerindeki siyahligi kaldır
        element.classList.remove("covered");

        // Kartın doğruluğunu kontrol et
        if (card === "card" + expectedCard) {
            // Doğru kart
            score += 20;
            expectedCard++;
            updateScore();

            // Skor 100'e ulaştığında kazandın mesajını göster
            if (score === 100) {
                document.getElementById("winMessage").innerText = "You win!";
            }
        } else {
            // Yanlış kart
            document.getElementById("message").innerText = "You lost!";
        }
    }
}

function updateScore() {
    document.getElementById("score").innerText = "Skor: " + score;
}

function resetMessages() {
    document.getElementById("message").innerText = "";
    document.getElementById("winMessage").innerText = "";
}

function restartGame() {
    location.reload(); // Sayfayı yeniden yükle
}