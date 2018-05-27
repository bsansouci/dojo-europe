[@bs.deriving abstract]
type data = {
  username: string,
  location: (float, float),
};

/* Make a POST request. */
let fetchPost: (~url: string, ~body: string) => unit;

let fetchGet: (~url: string, ~cb: array(data) => unit) => unit;
