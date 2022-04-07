const express = require('express')
const axios = require('axios')
const fs = require('fs')

const app = express()

let times = 0

app.get('/', function(request, response) {
  response.setHeader("Access-Control-Allow-Origin", "*");
  response.setHeader("Access-Control-Allow-Headers", "*");
  response.setHeader("Access-Control-Allow-Method", "*");
  axios({
    method: 'get',
    url: 'https://c.m.163.com/ug/api/wuhan/app/data/list-total'
  }).then(response => {
    fs.writeFileSync('./data.json', JSON.stringify(response.data), (err, data) => {
      console.log(err);
    })
    console.log(response.data);
  })
  setTimeout(() => {
    const dataNow = fs.readFileSync('./data.json', {encoding: 'utf-8'})
    response.send(dataNow.data.chinaTotal.today.confirm)
  }, 2000)
  times++
  console.log(`累计收到${times}次请求 --------`);
  response.send(`累计收到${times}次请求`)
})

app.listen(3000, function() {
  console.log('app is running at port 3000');
})

