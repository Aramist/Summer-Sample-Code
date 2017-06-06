var time = 0;
var enemies = [];
var bullets = [];
var playerDead = false;

var Scoreboard = function(){
    this.score = 0;
    this.addScore = function(dscore){
        this.score += dscore;
        this.score = this.score < 0 ? 0 : this.score;
        this.update();
    };
    this.update = function(){
        text("Score: " + this.score, 0, 0, 100, 100);
    };
};

var Missile = function(loc){
    this.position = loc;
    this.velocity = [0, -2];
    this.update = function(){
        this.position = [this.position[0] + this.velocity[0], this.position[1] + this.velocity[1]];
        if(this.position[1] <= 0){
            return false;
        }
        fill(0, 0, 255);
        ellipse(this.position[0], this.position[1], 5, 5);
        return true;
    };
};

var Enemy = function(xDist){
    this.position = [xDist, 0];
    this.update = function(){
        this.position[1] += 1;
        if(this.position[1] >= 400){
            return false;
        }
        noStroke();
        fill(255, 0, 0);
        ellipse(this.position[0], this.position[1], 10, 10);
        return true;
    };
};

var scores = new Scoreboard();
var Player = function(loc){
    this.position = loc;
    this.move = function(cx, cy){
        this.position = [cx, cy];
    };
    this.shoot = function(){
        bullets.push(new Missile(this.position));
    };
    this.special = function(){
        scores.addScore(-300);
        for(var i = -2; i <= 2; i++){
            var angle = 270 + 15 * i;
            var vx = cos(angle) * sqrt(5);
            var vy = sin(angle) * sqrt(5);
            var bul = new Missile(this.position);
            bul.velocity = [vx, vy];
            bullets.push(bul);
        }
    };
    this.update = function(){
        fill(0, 0, 255);
        ellipse(this.position[0], this.position[1], 15, 15);
    };
};

var play = new Player(200, 200);

var checkCollisions = function(missile){
    var i = 0;
    while(i < enemies.length){
        var dist = pow(enemies[i].position[0] - missile.position[0], 2) + pow(enemies[i].position[1] - missile.position[1], 2);
        var playerDist = pow(enemies[i].position[0] - play.position[0], 2) + pow(enemies[i].position[1] - play.position[1], 2);
        if(playerDist < 40){
            playerDead = true;
        }
        if(dist < 60){
            enemies.splice(i, 1);
            scores.addScore(200);
        }else{
            ++i;
        }
    }
};

mousePressed = function(){
    if(mouseButton === LEFT){
        play.shoot();
    }else if(mouseButton === RIGHT){
        play.special();
    }
};

mouseMoved = function(){
    play.move(mouseX, mouseY);
};

draw = function() {
    background(255, 255, 255);
    if(playerDead){
        text("You Were Destroyed", 150, 200);
        return;
    }
    ++time;
    if(time % 30 === 0){
        var randX = random(0, 399);
        enemies.push(new Enemy(randX));
    }
    var i = 0;
    while(i < enemies.length){
        var success = enemies[i].update();
        if(!success){
            enemies.splice(i, 1);
            scores.addScore(-50);
        }else{
            i++;
        }
    }
    i = 0;
    while(i < bullets.length){
        var success = bullets[i].update();
        if(!success){
            bullets.splice(i, 1);
        }else{
            checkCollisions(bullets[i]);
            i++;
        }
    }
    play.update();
    scores.update();
};
