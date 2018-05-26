module ComposableMap = {
  [@bs.deriving abstract]
  type projectionConfigT = {
    scale: int,
    rotation: array(int),
  };
  [@bs.deriving abstract]
  type jsProps = {
    projectionConfig: projectionConfigT,
    width: int,
    height: int,
    style: ReactDOMRe.Style.t,
  };
  [@bs.module "react-simple-maps"]
  external composableMap : ReasonReact.reactClass = "ComposableMap";
  let make = (~projectionConfig, ~width, ~height, ~style, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=composableMap,
      ~props=jsProps(~projectionConfig, ~width, ~height, ~style),
      children,
    );
};

module ZoomableGroup = {
  [@bs.deriving abstract]
  type jsProps = {
    center: array(int),
    disablePanning: bool,
  };
  [@bs.module "react-simple-maps"]
  external zoomableGroup : ReasonReact.reactClass = "ZoomableGroup";
  let make = (~center, ~disablePanning=false, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=zoomableGroup,
      ~props=jsProps(~center, ~disablePanning),
      children,
    );
};

module Geographies = {
  [@bs.deriving abstract]
  type jsProps = {geography: string};
  [@bs.module "react-simple-maps"]
  external geographies : ReasonReact.reactClass = "Geographies";
  let make = (~geography, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographies,
      ~props=jsProps(~geography),
      children,
    );
};

module Geography = {
  [@bs.deriving abstract]
  type geographyT = {id: string};
  type projectionT;
  [@bs.deriving abstract]
  type styleT = {
    default: ReactDOMRe.Style.t,
    hover: ReactDOMRe.Style.t,
    pressed: ReactDOMRe.Style.t,
  };
  [@bs.deriving abstract]
  type jsProps = {
    geography: geographyT,
    projection: projectionT,
    style: styleT,
  };
  [@bs.module "react-simple-maps"]
  external geographyComponent : ReasonReact.reactClass = "Geography";
  let make = (~geography, ~projection, ~style, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographyComponent,
      ~props=jsProps(~geography, ~projection, ~style),
      children,
    );
};

module Markers = {
  [@bs.module "react-simple-maps"]
  external markers : ReasonReact.reactClass = "Markers";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=markers, ~props=(), children);
};

module Marker = {
  [@bs.deriving abstract]
  type markerT = {
    markerOffset: int,
    coordinates: array(float),
    name: string,
  };
  [@bs.deriving abstract]
  type styleT = {
    default: ReactDOMRe.Style.t,
    hover: ReactDOMRe.Style.t,
    pressed: ReactDOMRe.Style.t,
  };
  [@bs.deriving abstract]
  type jsProps = {
    style: styleT,
    marker: markerT,
  };
  [@bs.module "react-simple-maps"]
  external markerComponent : ReasonReact.reactClass = "Marker";
  let make = (~style, ~marker, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=markerComponent,
      ~props=jsProps(~style, ~marker),
      children,
    );
};

let markers = [|
  Marker.markerT(
    ~markerOffset=-25,
    ~name="Buenos Aires",
    ~coordinates=[|(-58.3816), (-34.6037)|],
  ),
  Marker.markerT(
    ~markerOffset=-25,
    ~name="La Paz",
    ~coordinates=[|(-68.1193), (-16.4897)|],
  ),
  Marker.markerT(
    ~markerOffset=35,
    ~name="Brasilia",
    ~coordinates=[|(-47.8825), (-15.7942)|],
  ),
  Marker.markerT(
    ~markerOffset=35,
    ~name="Santiago",
    ~coordinates=[|(-70.6693), (-33.4489)|],
  ),
  Marker.markerT(
    ~markerOffset=35,
    ~name="Bogota",
    ~coordinates=[|(-74.0721), 4.7110|],
  ),
  Marker.markerT(
    ~markerOffset=35,
    ~name="Quito",
    ~coordinates=[|(-78.4678), (-0.1807)|],
  ),
  Marker.markerT(
    ~markerOffset=-25,
    ~name="Georgetown",
    ~coordinates=[|(-58.1551), 6.8013|],
  ),
  Marker.markerT(
    ~markerOffset=-25,
    ~name="Asuncion",
    ~coordinates=[|(-57.5759), (-25.2637)|],
  ),
  Marker.markerT(
    ~markerOffset=35,
    ~name="Paramaribo",
    ~coordinates=[|(-55.2038), 5.8520|],
  ),
  Marker.markerT(
    ~markerOffset=35,
    ~name="Montevideo",
    ~coordinates=[|(-56.1645), (-34.9011)|],
  ),
  Marker.markerT(
    ~markerOffset=-25,
    ~name="Caracas",
    ~coordinates=[|(-66.9036), 10.4806|],
  ),
|];

module Main = {
  /* still in Greeting.re */
  let component = ReasonReact.statelessComponent("Greeting");
  let make = _children => {
    ...component, /* spread the template's other defaults into here  */
    render: _self =>
      <div
        style=(
          ReactDOMRe.Style.make(
            ~width="100%",
            ~maxWidth="980px",
            ~margin="0 auto",
            (),
          )
        )>
        <ComposableMap
          projectionConfig=(
            ComposableMap.projectionConfigT(
              ~scale=205,
              ~rotation=[|(-11), 0, 0|],
            )
          )
          width=980
          height=551
          style=(ReactDOMRe.Style.make(~width="100%", ~height="auto", ()))>
          <ZoomableGroup center=[|0, 20|] disablePanning=false>
            <Geographies geography="world-50m.json">
              ...(
                   (geographies, projection) => {
                     Js.log(geographies);
                     ReasonReact.array(
                       Array.mapi(
                         (i, geography) =>
                           if (Geography.id(geography) === "ATA") {
                             <div key=(string_of_int(i)) />;
                           } else {
                             <Geography
                               key=(string_of_int(i))
                               geography
                               projection
                               style=(
                                 Geography.styleT(
                                   ~default=
                                     ReactDOMRe.Style.make(
                                       ~fill="#ECEFF1",
                                       ~stroke="#607D8B",
                                       ~strokeWidth="0.75px",
                                       ~outline="none",
                                       (),
                                     ),
                                   ~hover=
                                     ReactDOMRe.Style.make(
                                       ~fill="#607D8B",
                                       ~stroke="#607D8B",
                                       ~strokeWidth="0.75px",
                                       ~outline="none",
                                       (),
                                     ),
                                   ~pressed=
                                     ReactDOMRe.Style.make(
                                       ~fill="#FF5722",
                                       ~stroke="#607D8B",
                                       ~strokeWidth="0.75px",
                                       ~outline="none",
                                       (),
                                     ),
                                 )
                               )
                             />;
                           },
                         geographies,
                       ),
                     );
                   }
                 )
            </Geographies>
            <Markers>
              ...(
                   Array.mapi(
                     (i, marker) =>
                       <Marker
                         key=(string_of_int(i))
                         marker
                         style=(
                           Marker.styleT(
                             ~default=
                               ReactDOMRe.Style.make(~fill="#FF5722", ()),
                             ~hover=
                               ReactDOMRe.Style.make(~fill="#FFFFFF", ()),
                             ~pressed=
                               ReactDOMRe.Style.make(~fill="#FF5722", ()),
                           )
                         )>
                         <circle
                           cx="0"
                           cy="0"
                           r="6px"
                           style=(
                             ReactDOMRe.Style.make(
                               ~stroke="#FF5722",
                               ~strokeWidth="3px",
                               ~opacity="0.9",
                               (),
                             )
                           )
                         />
                         <text
                           textAnchor="middle"
                           y=string_of_int(Marker.markerOffset(marker))
                           style=(
                             ReactDOMRe.Style.make(
                               ~fontFamily="Roboto, sans-serif",
                               ~fill="#607D8B",
                               (),
                             )
                           )>
                           (ReasonReact.string(Marker.name(marker)))
                         </text>
                       </Marker>,
                     markers,
                   )
                 )
            </Markers>
          </ZoomableGroup>
        </ComposableMap>
      </div>,
  };
};

ReactDOMRe.renderToElementWithId(<Main />, "main");
