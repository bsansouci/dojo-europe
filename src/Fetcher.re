[@bs.deriving abstract]
type data = {
  username: string,
  location: (float, float),
};

type response1;
type promise('a);
[@bs.send] external json : response1 => 'a = "";

[@bs.deriving abstract]
type request = {
  [@bs.as "method"]
  method_: string,
  body: string,
};

[@bs.val] external fetchGet : string => promise(response1) = "fetch";

[@bs.val] external fetchPost : (string, request) => unit = "fetch";
let fetchPost = (~url, ~body) =>
  fetchPost(url, request(~method_="POST", ~body));

[@bs.send]
external then1 : (promise(response1), response1 => 'a) => promise('a) =
  "then";

[@bs.send]
external then2 : (promise(array(data)), array(data) => unit) => unit =
  "then";

let fetchGet = (~url, ~cb) => then2(then1(fetchGet(url), json), cb);
