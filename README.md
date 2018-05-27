Dojo World Edition® starter project
---

Hey everyone, welcome to the biggest Dojo yet! We have 25 cities across Europe (and a few other places) all organizing a local Dojo and this project will (literally) connect all of us together.

Your task will be to make a map of the world using ReasonReact, send your github username to our backend and get the location of everyone else to draw as dots on the map.

To draw the map you'll be binding to [react-simple-maps](https://github.com/zcreativelabs/react-simple-maps), which has a very useful [example here](https://github.com/zcreativelabs/react-simple-maps/blob/master/examples/basic-map/pages/index.js).

To get the locations of everyone, you should send a GET request to `https://immense-river-25513.herokuapp.com/locations` and you'll receive an array of `{username: string, location: (lat, long)}` (check `Fetcher.rei`).

To send your username send a POST request `https://immense-river-25513.herokuapp.com/add-location` with the body being just a string that's your username. The backend will figure out your location and store it.

A high level plan might look like:
1) clone this repo
2) setup ReasonReact and get a hello world working
3) look at react-simple-maps, write bindings to it (look at the [interop](https://reasonml.github.io/reason-react/docs/en/interop.html)) and get a dummy map working
4) Fetch the data from the backend
5) Draw markers for each team

*hint hint*: You should probably do some sort of polling at a regular interval to get the data as people finish the dojo ;)

This starter project only contains a bit of hairy fetching logic with promises, all you need to care about is calling `fetchGet` and `fetchPost`.

All deps are already setup so you can just install `npm install`.
Then run the build watcher `npm run watch`
Finally start a static server `npx serve` (with npm5/6) or `python -m SimpleHTTPServer` and go to the localhost address (`localhost:5000` or `localhost:8080` depending).

And please, don't be shy and ask questions! The organizers have the answers to everything.
