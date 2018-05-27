Dojo World Edition® starter project
---

Hey everyone, welcome to the biggest Dojo yet! We have 25 cities across Europe all organizing a local Dojo and this project will (literally) connect all of us together.

Your task will be to make a map of the world using ReasonReact, send your github username to our backend and get the location of everyone else to draw as dots on the map.

This starter project only contains a bit of hairy fetching logic with promises, all you need to care about is calling `fetchGet` and `fetchPost`.

To draw the map you'll be using [react-simple-map](https://github.com/zcreativelabs/react-simple-maps), which has a very useful [example here](https://github.com/zcreativelabs/react-simple-maps/blob/master/examples/basic-map/pages/index.js).

To get the location of everyone, you should send a GET request to `https://immense-river-25513.herokuapp.com/locations` and you'll receive an array of `{username: string, location: (lat, long)}` (check `Fetcher.rei`).

To send your username send a POST request `https://immense-river-25513.herokuapp.com/add-location` with the body being just a string that's your username. The backend will figure out your location and store it.

*hint hint*: You should probably do some sort of polling at a regular interval to get the data as people finish the dojo ;)
