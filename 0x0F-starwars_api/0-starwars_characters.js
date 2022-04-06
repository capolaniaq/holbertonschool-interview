#!/usr/bin/node

const request = require('request');

request.get('https://swapi-api.hbtn.io/api/films/' + process.argv[2], function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    for (let i = 0; i < characters.length; i++) {
      request.get(characters[i], function (error, response, body) {
        if (error) {
          console.log(error);
        } else {
          const character = JSON.parse(body);
          console.log(character.name);
        }
      });
    }
  }
});
